/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Part I: Write a basic quadratic function solver.
This code allows for raw input of a,b, and c.
Standalone script, have fun!
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/
#include <iostream>
#include <cmath>

int main() {
  // Instantiate coeffecients
  double a;
  double b;
  double c;

  // Allow user input for coeffs:

  std::cout << "Enter a: ";
  std::cin >> a;

  std::cout << "Enter b: ";
  std::cin >> b;

  std::cout << "Enter c: ";
  std::cin >> c;

  // Instantiate roots:
  double root1;
  double root2;

  // Solve
  root1 = ((-1*b)+std::sqrt((b*b)-(4*a*c))) / (2*a);

  root2 = ((-1*b)-std::sqrt((b*b)-(4*a*c))) / (2*a);

  // Output result to terminal
  std::cout << "Root 1 is " << root1 << "\n";
  std::cout << "Root 2 is " << root2 << "\n";
}
