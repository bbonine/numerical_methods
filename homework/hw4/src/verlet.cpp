/* 
********************************************************
File Name: verlet.cpp 
Description: Numerically Integrate
    d^2/dx^2 = -w^2 x
For w = m = k = 1 using the Velocity-Verlet algorithm
Date: 03/09/21
Author: Brett Bonine
******************************************************
*/

#include <iostream>
#include <cmath>
#include <fstream>  // save output

using namespace std;


// Energy Function 
double energy(double x,double v){
    double E;
    E = (0.5*pow(v, 2.)) + (0.5*(pow(x,2.)));       // U = 1/2 k (x2-x1)^2; E = T+U
    return E;  
}
// Momentum Function: P = mv
double mom(double m, double v){
    double p;
    p = m*v;
    return p;
}
// Force Function: F = -k (x2-x1)
double force(double x){
    double F;
    F = - x;

    return F;
}


//Intialize step info: atleast 10 steps per interval, 5 intervals
double steps = 100;
double pi = 3.1415;
double range = 5*2*pi;

double dt = range/steps;


//Initialize values to be called later
double p_old,p_new, x_old,x_new,v_old,v_new,a_old,a_new,t,E;
double m = 1;


// Main Program
int main(){
    cout <<"--------------------------------------------------------------------------------------- \n";
    cout <<"verlet.cpp: Solve a SHO via the Velocity-Verlet Integration Method. \n ";
    cout <<"--------------------------------------------------------------------------------------- \n";
    // Specify Initial Conditions
    cout << "Please enter Intiial Coniditons: \n";
    cout << "Initial position: ";
    cin >> x_old;

    cout << "Initial Velocity: ";
    cin >> v_old;

    // Calculate energy based off inputs
    E = energy(x_old, v_old);

    while (E == 0){
        cout << "WARNING! Initial energy should be non-zero. \n";
        cout << "Not a dynamically interesting system then, is it? Please enter new values: \n";
        cout << "Initial position: \n";
        cin >> x_old;

        cout << "Initial Velocity: \n";
        cin >> v_old;
        E = energy(x_old, v_old);
    }

    // Calculate momentum from inputs
    p_old = mom(m,v_old);
    
    // Begin integration:
    ofstream myfile;
	myfile.open("../outputs/verlet.txt");
    
    // Record Initial Values
    myfile << "TIME \t POS \t VEL \t ENR \n";
    myfile << t << "\t" << x_old << "\t" << v_old << "\t" << E << "\n"; 
    for (int i = 1; i < steps; i++){
        t = t + dt;
        x_new = x_old + (mom(m,v_old)*(dt/m))+ (pow(dt,2)/(2*m)*force(x_old)); // New positions


        p_new = p_old + ((dt/2)*(force(x_old)+force(x_new))); // Find velocity at new step

        E = energy(x_new,p_new/m);

        
        myfile << t << "\t" << x_new << "\t" << v_new << "\t" << E << "\n"; 	//write to file
        // Update values for next iteration
        x_old = x_new;
        p_old = p_new;
        v_old = p_new/m;
        




    }
    myfile.close();
    cout << "Integration Complete! See output file for results.";
}