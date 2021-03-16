/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% prob_2a.cpp
% This program (attemps) to use the multivariate
% formualtion of the Newton-Rhapson method to find
% the roots of the non-linear system of equations
%  sin(x+y) = 0
%  cos(x-y) = 0
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <iostream>
#include <vector>   // vectors
#include <cmath>    // sin, cos


// Initialize variables
double hx = 1,hy = 1;
double x = 1, y = 0;
int iter = 0;
int max_iter = 100;

static double epsilon = 0.001; //arbitary cutoff


// Analytic matrix multiplication of inverse of Jacobian
double x_corr(double x,double y){

  hx= ((sin(x+y)*sin(x-y))-(cos(x-y)*cos(x+y)))/(2*cos(x+y)*sin(x-y));
  return hx;
}

double y_corr(double x,double y){

  hy= ((sin(x+y)*sin(x-y))+(cos(x-y)*cos(x+y)))/(2*cos(x+y)*sin(x-y));
  return hy;
}

int main(){
  std::cout <<  "\n";
  std::cout << "--------------------------------------------------------- \n";
  std::cout << "Please enter your initial root guess or use the default: \n";
  std::cout << "--------------------------------------------------------- \n";
  std::cout <<  "\n";

  std::cout <<  "Guess for x0 (1): ";
  std::cin >>  x;
  std::cout <<  "Guess for y0 (0): ";
  std::cin >>  y;

  double pi = 3.1415;

  while ((x > 2*pi || y >2*pi) || (x< -2*pi || y< - 2*pi)){
    std::cout<<"---------------------------- ERROR: -------------------- \n";
    std::cout<<"Please restrict initial guess between -2pi and 2pi.Try again:\n";
    std::cout <<"-------------------------------------------------------\n ";
    std::cout <<  "\n";

    std::cout <<  "Guess for x0 (1): ";
    std::cin >>  x;
    std::cout <<  "Guess for y0 (0): ";
    std::cin >>  y;

  }

  // Begin Newton-Raphson

  while ((std::abs(hx) && std::abs(hy) >= epsilon) && iter < max_iter){

    hx = x_corr(x,y);
    hy = y_corr(x,y);
    x = x - hx;
    y = y - hy;
    iter += 1;


  }

/*
Debug
*/
std::cout << "\n";
std::cout << "-------------------------SUMMARY------------------------- \n";


if (iter == max_iter){

  std::cout<<"WARNING! Program failed to converge after "<<iter<<" iterations.\n";
  std::cout << "Please try again with different values. \n";
  std::cout << "Last guess for x: " << x << "\n";
  std::cout << "Last guess for y: " << y << "\n";
  std::cout << "\n";
  std::cout << "Last change in x: " << hx << "\n";
  std::cout << "Last change in y: " << hy << "\n";

}
else{

  std::cout << "Program has converged after " << iter << " iterations! \n";
  std::cout << "Best guess for x: " << x << "\n";
  std::cout << "Best guess for y: " << y << "\n";
  std::cout << "\n";
  std::cout << "Final change in x: " << hx << "\n";
  std::cout << "Final change in y: " << hy << "\n";

std::cout <<"--------------------------------------------------------- \n";
}











}
