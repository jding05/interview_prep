#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"
#define RED 18.0
#define GREEN 1.0
#define TOTAL 37.0

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	if (firstDollarsBet >= dollarsWanted)
		return 1;
	if (nbGame == 0)
		return 0;
	double prob = probabilityWin(firstDollarsBet * 2, dollarsWanted, nbGame - 1) * RED / TOTAL;
	prob += probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame - 1) * GREEN / TOTAL;
	return prob;
}
