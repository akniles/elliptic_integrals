#include<iostream>
#include<cmath>
#include<gmpxx.h>

static const char* PI = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989@0";


class Sequence {
public:
	Sequence(mp_bitcnt_t set_precision);

	~Sequence();

    void AGM(double a, double b, int iters, mpf_t* result);

    void MAGM(double a, double b, int iters, mpf_t* result);

private:
	mpf_t x;
	mpf_t y;
	mpf_t z;
	mp_bitcnt_t precision;
};


void FirstKind(double k, mp_bitcnt_t set_precision, mpf_t* result);

void SecondKind(double k, mp_bitcnt_t set_precision, mpf_t* result);

// mpf_t calculate_pi(double beta);

int main() {
	mp_bitcnt_t precision = 100;
	std::cout.precision(precision);
	mpf_t result;
	mpf_init(result);
	SecondKind(std::sqrt(2) / 2, precision, &result);
	std::cout << result << "\n";
	return 0;
}

Sequence::Sequence(mp_bitcnt_t set_precision) {
    precision = set_precision;
	mpf_set_default_prec(precision);
	mpf_init(x);
    mpf_init(y);
    mpf_init(z);
    mpf_set_ui(x, 0);
    mpf_set_ui(y, 0);
    mpf_set_ui(z, 0);
}

Sequence::~Sequence() {
	mpf_clear(x);
	mpf_clear(y);
	mpf_clear(z);
}

void Sequence::AGM(double a, double b, int iters, mpf_t* result) {
	if (a < b) {
		std::swap(a, b);
	}
	mpf_set_d(x, a);
	mpf_set_d(y, b);

    mpf_t x_next;
    mpf_t y_next;
    mpf_init(x_next);
    mpf_init(y_next);
    for (size_t index = 0; index < iters; ++index) {
        mpf_add(x_next, x, y);
        mpf_div_ui(x_next, x_next, 2);
        
        mpf_mul(y_next, x, y);
        mpf_sqrt(y_next, y_next);
        
        mpf_set(x, x_next);
        mpf_set(y, y_next);
    }
    mpf_set(*result, x);
    mpf_set_ui(x, 0);
    mpf_set_ui(y, 0);
    mpf_set_ui(z, 0);
    mpf_clear(x_next);
    mpf_clear(y_next);
}

void Sequence::MAGM(double a, double b, int iters, mpf_t* result) {
    if (a < b) {
		std::swap(a, b);
	}
	mpf_set_d(x, a);
	mpf_set_d(y, b);

    mpf_t x_next;
    mpf_t y_next;
    mpf_t z_next;
    mpf_t cache;
    mpf_init(x_next);
    mpf_init(y_next);
    mpf_init(z_next);
    mpf_init(cache);
    for (size_t index = 0; index < iters; ++index) {
        mpf_add(x_next, x, y);
        mpf_div_ui(x_next, x_next, 2);
        
        mpf_sub(y_next, y, z);
        mpf_sub(z_next, x, z);
        mpf_mul(z_next, z_next, y_next);
        mpf_sqrt(z_next, z_next);
        mpf_add(y_next, z, z_next);

		mpf_sub(cache, y, z);
		mpf_sub(z_next, x, z);
		mpf_mul(z_next, z_next, cache);
        mpf_sqrt(z_next, z_next);
        mpf_sub(z, z, z_next);

        mpf_set(x, x_next);
        mpf_set(y, y_next);
    }
    mpf_set(*result, x_next);

    mpf_clear(x_next);
    mpf_clear(y_next);
    mpf_clear(z_next);
}

void FirstKind(double k, mp_bitcnt_t set_precision, mpf_t* result) {
	Sequence sequence(set_precision);
	sequence.AGM(1, std::sqrt(1 - k * k), 10, result);
	mpf_mul_ui(*result, *result, 2);

	mpf_t pi;
	mpf_init(pi);
	mpf_set_str(pi, PI, 10);
    mpf_div(*result, pi, *result);
    mpf_clear(pi);
}

void SecondKind(double k, mp_bitcnt_t set_precision, mpf_t* result) {
	Sequence sequence(set_precision);
	sequence.AGM(1, std::sqrt(1 - k * k), 10, result);
	mpf_mul_ui(*result, *result, 2);

	mpf_t pi;
	mpf_t magm;
	mpf_init(pi);
	mpf_init(magm);
	mpf_set_str(pi, PI, 10);
    mpf_div(*result, pi, *result);
    sequence.MAGM(1, 1 - k * k, 10, &magm);
    mpf_mul(*result, *result, magm);
    mpf_clear(pi);
    mpf_clear(magm);
}

// float_b calculate_pi_magm(float_b beta) {
// }
