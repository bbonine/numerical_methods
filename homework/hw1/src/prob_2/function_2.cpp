//function_2.cpp

/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Part II: Make the quadratic solvera subroutine
in a separate file. This file will contain our
function to be called.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <cmath>

//Include header
#include "quad_2.h"

//Declare function. Input: coeffs of quadratic function
double quad_root_1(double a, double b, double c)
{
  double r1;
  r1 = ((-1*b)+std::sqrt((b*b)-(4*a*c))) / (2*a);
  return r1;
}

double quad_root_2(double a, double b, double c)
{
  double r2;
  r2 = ((-1*b)-std::sqrt((b*b)-(4*a*c))) / (2*a);
  return r2;

}
