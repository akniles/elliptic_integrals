#ifndef EINTEGRALS_AGM_H
#define EINTEGRALS_AGM_H

#include <cstring>
#include <cmath>
#include <string>
#include <gmpxx.h>

class AGM {
public:
	AGM();

	~AGM();

	std::string operator()(double a, double b, size_t precision);

private:
	// void NextIteration();
	mpf_t x;
	mpf_t y;
};

#endif // EINTEGRALS_AGM_H