//function_3.cpp

/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Part II: Make the quadratic solvera subroutine
in a separate file. This version includes the roots
using the method from class.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <cmath>

//Include header
#include "quad_3.h"

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
//Declare function using method from class
double quad_root_3(double r1, double c)
{
  double r3;
  r3 = c/r1 ;
  return r3;

}
