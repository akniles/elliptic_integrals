#ifndef EINTEGRALS_MAGM_H
#define EINTEGRALS_MAGM_H

#include <iostream>
#include <cmath>
#include <string>
#include <gmpxx.h>

class MAGM {
public:
	MAGM(int set_precision);

	~MAGM();

	std::string operator()(double a, double b, int iters = 100);

private:
	void NextIteration();
	mpf_t x;
	mpf_t y;
	mpf_t z;
	mp_bitcnt_t precision;
};	

#endif // EINTEGRALS_MAGM_H
