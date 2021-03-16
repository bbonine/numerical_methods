/*
 ###################################################################
 File name: odeint_solver.cpp
 Description: Numerically Integrate
    d^2/dx^2 = -w^2 x
 For w = m = k = 1 using the Burlich-Stoer routine
 Date: 03/09/21
 Author: Brett Bonine
 ###################################################################
*/

// Libraries
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "nr.h"	// Link to oedint header files
using namespace std;

//Function for derivatives: Now 2e
void derivs(const DP x,Vec_I_DP &y,Vec_O_DP &dy){
    
    // We'll store position and velocity in2d vector y = [x, v]:
    dy[0] = y[1]; //  Velocity
    dy[1] = -y[0]; // Acceleration
    return;
}


// Parameters
double h, hmin, eps = 1e-4;
int nsteps = 100;
const int ndim = 2;
const double pi = 3.14159;

// Parameters added to work with OEDINT
DP dxsav;
int kmax, kount;
int nok=0, nbad = 0;
Vec_DP *xp_p;
Mat_DP *yp_p;


// Outputs
double x_old, x_new,v_old, v_new, t; 


int main(){
	cout << "------------------------------------------------------ \n";
	cout << "BURLICH-STOER SOLVER: Input desired user params \n";
	cout << "-------------------------------------------------- \n";

	cout << "Number of steps " <<"("<<nsteps<<"): " ;
	cin >> nsteps;

	cout << "Desired Relative Error " <<"("<<eps<<"): " ;
	cin >> eps;

	// Update values from user input
	h = (10*pi)/nsteps; //step size: 5 cycles of 2pi
	hmin = 1e-4*h;


    // Specify Initial Conditions
    cout << "Please enter Intiial Coniditons: \n";
    cout << "Initial position: ";
    cin >> x_old;

    cout << "Initial Velocity: ";
    cin >> v_old;


    Vec_IO_DP y(ndim); // Current Y value, svaed as vector
	// Boundary Conditions: 
	y[0] = x_old;
    y[1] = v_old;

	// Preprare output file
	ofstream myfile;
	myfile.open("output_odeint.txt");

    // Record Initial Values
    myfile << "TIME \t POS \t VEL \n";
    myfile << t << "\t" << y[0] << "\t" << y[1] << "\n"; 
	// Loop through each step
	for (int i = 1; i < nsteps; i++){
        t = t + h;
		x_new = x_old + h;
		NR::odeint(y,x_old,x_new,eps,h,hmin,nok,nbad,derivs,NR::bsstep);
		x_old = x_new;
        
		
		myfile << t << "\t" << y[0] << "\t" << y[1] << "\n";  	//write to file
		
		
		//cout << y_val[0]<<"\n"; 
	}	
cout << "Program successful. See output file for results. \n"; 
}