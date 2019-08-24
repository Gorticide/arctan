#include <iostream>
#include <cmath>     // atan
#include <cstdlib>   // atof
#include <string>  // std::string

std::string printQuadrant(int abscissa, int ordinate);
double Arctan(double ordinate_y, double abscissa_x);

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
      double theta = Arctan(y, x);

      std::cout << std::endl;
      std::cout << theta << " radians = " << theta * degrees << " degrees\n\n";

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
	  std::cout << "\narctan(" << y << "/" << x << ") = " << Arctan(y, x)
              << " radians = " << Arctan(y, x) * degrees << " degrees\n\n";
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

double Arctan(double ordinate_y, double abscissa_x)   {
  double x = abscissa_x;
  double y = ordinate_y;
  double angle, phi;

  // First we must check for vertical vectors.
  // If the vector is vertical, then x == 0, so we cannot use atan(y/x):

  if (x == 0) angle = PI/2;

  // We begin with an angle calculated into the first quadrant by using the
  // absolute value of y/x, then multiples of PI/2 have to be added or subtracted
  // to get the angle into the correct quadrant

  else angle = atan(std::fabs(y/x));   // angle in radians in Quadrant I

  // We keep in terms of radians, and will use constant defined globally:
  //    const double PI = acos(-1);

  if (x >= 0 && y >= 0) phi = angle;           // Quadrant I
  if (x <= 0 && y >= 0) phi = PI - angle;      // Quadrant II
  if (x <= 0 && y <= 0) phi = PI + angle;      // Quadrant III
  if (x >= 0 && y <= 0) phi = 2*PI - angle;    // Quadrant IV (positive value)

  // We will return angle phi, also in radians, in correct quadrant
  // Then, that result in radians can be transformed when printing ( *degrees ):
  // const double degrees = 180.0/PI;

  return phi;

}
