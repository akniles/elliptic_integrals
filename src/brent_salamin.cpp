#include <gmpxx.h>
#include <iostream>
#include <string>
#include <cmath>

std::string CalculatePi(size_t precision) {
	size_t iters = std::max(static_cast<int>(std::log(precision)), 10);
    size_t mpf_precision = 5 * precision;
    mpf_set_default_prec(mpf_precision);
	mpf_t a, b, t, p;
	mpf_t ta;
	mpf_t shift, pi;
	mpf_init(shift);
	mpf_init(pi);
	mpf_init(ta);
	mpf_init_set_d(a, 1);
	mpf_init_set_d(b, 0.5);
	mpf_sqrt(b, b);
	mpf_init_set_d(t, 0.25);
	mpf_init_set_d(p, 1);
	for (size_t index = 0; index < iters; ++index) {
		mpf_add(ta, a, b);
		mpf_div_ui(ta, ta, 2);
		// a_{n+1} = (a_n + b_n) / 2
		mpf_mul(b, a, b);
		mpf_sqrt(b, b);
		// b_{n+1} = (a_n b_n)^(1/2)
		mpf_sub(shift, a, ta);
		mpf_mul(shift, shift, shift);
		mpf_mul(shift, p, shift);
		mpf_sub(t, t, shift);
		// t_{n+1} = t_n - p_n (a_n - a_{n+1})^2
		mpf_mul_ui(p, p, 2);
		mpf_set(a, ta);
	}
	
	mpf_add(pi, a, b);
	mpf_mul(pi, pi, pi);
	mpf_div_ui(pi, pi, 4);
	mpf_div(pi, pi, t);
	// pi = (a + b)^2 / 4t
	char* cstr_result = new char[mpf_precision];
	mp_exp_t exp;
	mpf_get_str(cstr_result, &exp, 10, 0, pi);
	std::string str_result(cstr_result);
	str_result = "0." + str_result.substr(0, precision) + "@" + std::to_string(exp);

	mpf_clear(shift);
	mpf_clear(pi);
	mpf_clear(a);
	mpf_clear(b);
	mpf_clear(t);
	mpf_clear(p);
	mpf_clear(ta);

	delete[] cstr_result;

	return str_result;
}
