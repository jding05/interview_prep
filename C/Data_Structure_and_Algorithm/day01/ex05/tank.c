#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

struct s_tank *initTank(void)
{
	struct s_tank *tank = (struct s_tank *)malloc(sizeof(struct s_stack));
	if (tank == 0)
		return 0;
	tank->stacks = 0;
	tank->n = 0;
	return (tank);
}


void add_stack(struct s_tank *tank)
{
	printf("hi");
	if (!tank)
		return ;
	tank->n++;
	tank->stacks = realloc(tank->stacks, sizeof(struct s_stack*) * (tank->n));
	tank->stacks[tank->n -1] = (struct s_stack *)malloc(sizeof(struct s_stack));
	bzero(tank->stacks[tank->n -1], sizeof(struct s_stack));
}

void add_elem(struct s_stack *stack, int energy)
{
	if (!stack)
		return ;
	struct s_elem *elem = (struct s_elem *)malloc(sizeof(struct s_elem));
	elem->energy = energy;
	elem->next = stack->elem;
	stack->elem = elem;
	stack->sum += energy;
}

void tankPush(struct s_tank *tank, int energy)
{
	if (tank == 0 || energy < 10 || energy > 100)
		return ;
	if (!tank->stacks || tank->stacks[tank->n -1]->sum + energy > 1000)
		add_stack(tank);
	add_elem(tank->stacks[tank->n -1], energy);
}

int tankPop(struct s_tank *tank)
{
	if (!tank || !tank->stacks || !tank->stacks[0] || !tank->stacks[0]->elem)
		return (0);
	int energy = tank->stacks[tank->n - 1]->elem->energy;
	if ((tank->stacks[tank->n -1]->sum -= energy) <= 0)
	{	
		free(tank->stacks[tank->n -1]->elem);
		free(tank->stacks[tank->n -1]);
		if (tank->n > 1)
			tank->stacks = realloc(tank->stacks, sizeof(struct s_stack*) * (tank->n -1));
		else
			tank->stacks = 0;
		tank->n--;
	}
	else
	{
		struct s_elem *elem = tank->stacks[tank->n -1]->elem->next;
		free(tank->stacks[tank->n -1]->elem);
		tank->stacks[tank->n -1]->elem = elem;
	}
	return energy;
}
