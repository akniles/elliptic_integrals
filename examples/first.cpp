#include <iostream>
#include "../eintegrals.h"

int main() {
	std::cout << "Enter precision: \n";
	int precision;
	double eccentricity;
	std::cin >> precision;
	std::cout.precision(precision);
	SecondKind second_kind_integral;
	FirstKind first_kind_integral;
	std::cout << "Enter eccentricity(0 < e < 1): \n";
	std::cin >> eccentricity;
	std::cout << "Value of complete elliptic integral of the first kind with given eccentricity is:\n"  
			  << first_kind_integral(std::sqrt(2) / 2, precision) 
			  << "\nValue of complete elliptic integral of the second kind with given eccentricity is:\n" 
			  << second_kind_integral(std::sqrt(2) / 2, precision)
			  << "\n";
	return 0;
}