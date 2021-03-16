/*
 * %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * File name: intbsstep.cpp
 *
 * Description: Read in function to solve differential equation
 *   df(x)/dx = -cos(x)
 *   Using the numerical recipes Burlich-Stoer algorithm.
 *  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 *   */

// Libraries
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "nr.h"	// Link to oedint header files
using namespace std;

//Function for derivative
void deriv(const DP x,Vec_I_DP &y,Vec_O_DP &dy){
    dy[0] = -cos(x);
}

// Parameters
double h, hmin, eps = 1e-4;
int nsteps = 100;
const int ndim = 1;
const double pi = 3.14159;

// Parameters added to work with OEDINT
DP dxsav;
int kmax, kount;
int nok=0, nbad = 0;
Vec_DP *xp_p;
Mat_DP *yp_p;


// Outputs
double x_current = 0, x_new = 0;
Vec_IO_DP y_val(ndim); // Current Y value, svaed as vector

int main(){
	cout << "------------------------------------------------------ \n";
	cout << "BURLICH-STOER SOLVER: Input desired user params \n";
	cout << "-------------------------------------------------- \n";

	cout << "Number of steps " <<"("<<nsteps<<"): " ;
	cin >> nsteps;

	cout << "Desired Relative Error " <<"("<<eps<<"): " ;
	cin >> eps;

	// Update values from user input
	h = (20*pi)/nsteps; //step size
	hmin = 1e-4*h;

	// Boundary Conditions
	y_val[0] = 0;

	// Preprare output file
	ofstream myfile;
	myfile.open("output_bs_"+to_string(nsteps)+"steps.txt");
	// Loop through each step
	for (int i = 1; i < nsteps; i++){
		x_new = x_current + h;
		NR::odeint(y_val,x_current,x_new,eps,h,hmin,nok,nbad,deriv,NR::bsstep);
		x_current = x_new;
		
		myfile << x_new << "\t" << y_val[0] << "\n"; 	//write to file
		
		
		//cout << y_val[0]<<"\n"; 
	}	
cout << "Program successful. See output file for results. \n"; 
}
