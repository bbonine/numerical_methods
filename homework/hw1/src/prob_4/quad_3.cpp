//quad_3.cpp

/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Part IV: Make the quadratic solver a subroutine
This time, include the method discussion from class
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/


//Link to header file
#include <iostream>
#include <stdlib.h>     // for exit
#include <iomanip>      // std::setprecision
#include "quad_3.h"

/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Begin main program
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/


int main(){
// Some text to demonstrate that the main file is working
  std::cout << "-----------------------------------------------------\n ";
  std::cout << "Version 3: Now finding the second root from the first! \n ";
  std::cout << "Please enter the coefficients of your choice. \n";
  std::cout << "-----------------------------------------------------\n";
  // User input of coefficients

  double a;
  std::cout << "Enter a: ";
  std::cin >> a;
  double b;
  std::cout << "Enter b: ";
  std::cin >> b;
  double c;
  std::cout << "Enter c: ";
  std::cin >> c;


/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Vibe Check: Make sure these coefficients don't mess things up
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

// Check for bad coefficients
if (a == 0){
  std::cout << "---------------------- ERROR ---------------------------\n";
  std::cout << "a=0? This isn't a quadratic equation now, is it? \n";
  std::cout << "Please try again. \n";
  std::cout << "\n";
  exit(EXIT_FAILURE);
}

// Check for non-real roots:

if ((4*a*c) > (b*b)){
  std::cout << "------------------------------------------------------\n";
  std::cout << "This quadratic equation has imaginary roots, please check another.";
  std::cout << "\n";
  exit(EXIT_SUCCESS);
}

/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Original Method:
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

  // Evaluate function
  std::cout << "\n";
  std::cout << "Standard method: \n";
  std::cout << "-----------------------------------------------------\n";
  double root1;
  root1 = quad_root_1(a,b,c);
  std::cout << "The first root is: " << std::setprecision(16) << root1 <<"\n";


  double root2;
  root2 = quad_root_2(a,b,c);
  std::cout << "The second root is: " <<std::setprecision(16) <<  root2 << "\n";

  std::cout << "                \n";

  /*
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   Method from class:
  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  */

  std::cout << "Method from class: Divide c by root 1: \n";
  std::cout << "-----------------------------------------------------\n";
  double root3;

  root3 = quad_root_3(root1,c);
  std::cout << "The second root can be found from the first as: " <<std::setprecision(16) << root3 <<"\n";

  std::cout << "                \n";



  std::cout << "Have a nice day! \n";

}
