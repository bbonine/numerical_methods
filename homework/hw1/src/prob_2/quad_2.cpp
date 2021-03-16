//main.cpp

/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Part II: Make the quadratic solver a subroutine
in a separate file. This will be the main file
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/


//Link to header file
#include <iostream>
#include "quad_2.h"


/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Begin main program
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/


int main(){
// Some text to demonstrate that the main file is working
  std::cout << "-----------------------------------------------------\n ";
  std::cout << "This routine calls functions in a separate file. Neat! \n ";
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



  // Evaluate function
  std::cout << "-----------------------------------------------------\n";
  double root1;
  root1 = quad_root_1(a,b,c);
  std::cout << "The first root is: " << root1 <<"\n";


  double root2;
  root2 = quad_root_2(a,b,c);
  std::cout << "The second root is " << root2 << "\n";

  std::cout << "                \n";
  std::cout << "Have a nice day! \n";

}
