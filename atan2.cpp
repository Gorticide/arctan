#include <iostream>
#include <cmath>     // atan2
#include <cstdlib>   // atof
#include <string>  // std::string

std::string printQuadrant(int abscissa, int ordinate);

const double PI = acos(-1);
const double degrees = 180.0/PI;

int main(int argc, char *argv[])  {

      if (argc!= 3)  {
	std::cout << "[USE] : " << argv[0] << " <ordinate y> <abscissa x> ";
  std::cout << "\nYou cannot have " << argc - 1 << " parameters.\n\n";
	return -1;
     }
      double y = atof(argv[1]);
      double x = atof(argv[2]);

      std::cout << std::endl;
      std::cout << atan2(y, x) << " radians = " << atan2(y, x) * degrees << " degrees\n\n";

      int check = 1;
      int done = 1;

      do {
	std::cout << "CHECK # " << check << ":\n";
	std::cout << "You entered coordinates x = " << x << " and y = " << y << "\n";
  std::cout << "The position vector [" << x << ", " << y << "] is " << printQuadrant(x, y);
	std::cout << "Enter the number 0 to exit or any other number to enter coordinates again: ";
	std::cin >> done;

	if (done == 0)
	   break;

	else {
	  std::cout << "\nEnter y-coordinate first.\n";
	  std::cout << "This is the numerator of y/x in arctan(y/x): ";
	  std::cin >> y;
	  std::cout << "\nNow enter the x-coordinate,\n";
	  std::cout << "the donominator of y/x in arctan(y/x): ";
	  std::cin >> x;
	  std::cout << "\narctan(" << y << "/" << x << ") = " << atan2(y, x) << " radians = " << atan2(y, x) * degrees << " degrees\n\n";
	}
	check += 1;

      } while (done != 0);
      return 0;
}


std::string printQuadrant(int abscissa, int ordinate)  {

  int x = abscissa;
  int y = ordinate;

  if (x == 0) {
    if (y == 0) return std::string("at the origin.");
    if (y > 0) return std::string("on the positve side of the y-axis.\n\n");
    if (y < 0) return std::string("on the negative side of the y-axis.\n\n");
  }
  else  {
    if (x > 0)  {
      if (y == 0) return std::string("on the positve side of the x-axis.\n\n");
      if (y > 0) return std::string("in Quadrant I.\n\n");
      if (y < 0) return std::string("in Quadrant IV.\n\n");
    }
   if (x < 0) {
        if (y == 0) return std::string("on the negative side of the x-axis.\n\n");
        if (y > 0)  return std::string("in Quadrant II.\n\n");
        if (y < 0)  return std::string("in Quadrant III.\n\n");
      }
  }

}
