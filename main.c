#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "main.h"

void main()
{
    int x[4], y[4];
    int i;

    printf ("Enter the x- and y-coordinates of the four control points.\n");
    for (i=0; i<4; i++)
	scanf ("%d%d", &x[i], &y[i]);

    bezier (x, y);
}
