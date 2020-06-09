#include <iostream>
#include "../src/eintegrals.h"

int main() {
	size_t precision;
	std::cout << "Enter precision(positive integer):\n";
	std::cin >> precision;
	auto pi = CalculatePi(precision);
	std::cout << "Pi is:\n" << pi << "\n";
	return 0;
}
