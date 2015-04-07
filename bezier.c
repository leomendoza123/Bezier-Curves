#include "bezier.h"
#include "bresemham.h"





void bezier (int x[4], int y[4])
{



    int i;
    double t;
    int firstPointX, firstPointY, secondPointX, secondPointY;
    double xt, yt;



    firstPointX = x[0];
    firstPointY = y[0];
    for (t = 0.0; t < 1.0; t += 0.0005)
    {
    	xt = pow (1-t, 3) * x[0] + 3 * t * pow (1-t, 2) * x[1] +
		    3 * pow (t, 2) * (1-t) * x[2] + pow (t, 3) * x[3];

    	yt = pow (1-t, 3) * y[0] + 3 * t * pow (1-t, 2) * y[1] +
		    3 * pow (t, 2) * (1-t) * y[2] + pow (t, 3) * y[3];
    	secondPointX = xt;
    	secondPointY = yt;
    	algoritmoBresemham ( firstPointX,  firstPointY,  secondPointX,  secondPointY);
    	firstPointX = secondPointX;
    	firstPointY = secondPointY;

    }
    secondPointX = x[3];
    secondPointY = y[3];
	algoritmoBresemham ( firstPointX,  firstPointY,  secondPointX,  secondPointY);


  //  Imprime puntos centrales
  //  for (i=0; i<4; i++)
  //  printf (">X: %i, Y: %i", x[i], y[i]);

    return;
}
