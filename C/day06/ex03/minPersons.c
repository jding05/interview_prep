#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"


int		minPersons(int elements, int minPercentage)
{
	int ppl = 1;
	double prob_not_hit = 1.0;
	double prob = 0.0;
	if (elements == 0 || minPercentage == 0)
		return 0;
	double minProb = (double)minPercentage / 100.0;
	int sub = 1;
	while (prob < minProb)
	{
		prob_not_hit *= (1 - (double)sub / (double)elements);
		prob = 1 - prob_not_hit;
		sub++;
		ppl++;
	}
	return ppl;
}


// the other way of writing
// int		minPersons(int elements, int minPercentage)
// {
// 	int ppl = 1;
// 	if (minPercentage > 100)
// 		minPercentage = 100;
// 	double prob = 0;
// 	double minProb = (double)minPercentage / 100.0;
// 	while (prob < minProb)
// 	{
// 		double possibleToHit = (double)ppl / (double)elements;
// 		prob += (1.0 - prob) * possibleToHit;
// 		ppl++;
// 	}
// 	return ppl;
// }