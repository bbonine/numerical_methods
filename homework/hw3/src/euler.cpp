/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% euler.cpp
% Solve the equation
%
% dy/dx = -cosx
%
% Using the Euler and Euler-Predictor Methods
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <iostream>
#include <fstream>  // save output
#include <cmath>    // sin, cos
using namespace std;


//Intialize step info: atleast 10 steps per interval, 10 intervals
const int steps = 100;
double pi = 3.1415;
double range = 10*2*pi;

double h = range/steps;


// Initialize arrays
double y_euler [steps];
double y_mod_euler [steps];
double x_vals [steps];

// ODE to solve
double func(double x){

  double dy;
  dy = -cos(x);
  return dy;
}

int main(){
  ofstream myfile ("output_euler.txt");
  if (myfile.is_open()){


    // Populate x values
    for (int i = 1; i < steps; i++){
      x_vals[i] = x_vals[i-1]+h;
    }

    // Main loop
    for(int i = 1; i < steps; i++){

      //Euler Method
      y_euler[i] = y_euler[i-1] + (h*func(x_vals[i-1]));

      // Modified Euler Method
      y_mod_euler[i] = y_mod_euler[i-1]+(h*(func(x_vals[i-1])+func(x_vals[i]))/2);

      // Write to file
      myfile << x_vals[i] << "\t";
      myfile << y_euler[i] << "\t";
      myfile << y_mod_euler[i] << "\n";

      }
    myfile.close();
    }

cout << "Program successfully Run. See output file for results. \n";

}
