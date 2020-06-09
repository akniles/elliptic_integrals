#ifndef EINTEGRALS_MAGM_H
#define EINTEGRALS_MAGM_H

#include <cstring>
#include <cmath>
#include <string>
#include <gmpxx.h>

class MAGM {
public:
	MAGM();

	~MAGM();

	std::string operator()(double a, double b, size_t precision);

private:
	// void NextIteration();
	mpf_t x;
	mpf_t y;
	mpf_t z;
};	

#endif // EINTEGRALS_MAGM_H
