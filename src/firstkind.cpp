#include "firstkind.h"
#include "brent_salamin.cpp"

std::string FirstKind::operator()(double k, size_t precision) {
	size_t mpf_precision = 5 * precision;
    mpf_set_default_prec(mpf_precision);
    size_t int_base = 10;

	AGM agm;
	mpf_t result;
	mpf_t pi;
	mpf_init(result);
	mpf_init(pi);
	auto agm_value = agm(1, std::sqrt(1 - k * k), mpf_precision);
	char *cstr_result = new char[mpf_precision];
	mp_exp_t exp;

	mpf_set_str(result, agm_value.c_str(), int_base);
	mpf_mul_ui(result, result, 2);

	mpf_set_str(pi, CalculatePi(mpf_precision).c_str(), int_base);
    mpf_div(result, pi, result);
    mpf_get_str(cstr_result, &exp, int_base, mpf_precision, result);
    mpf_clear(pi);
    mpf_clear(result);
	std::string str_result(cstr_result);
    str_result = "0." + str_result.substr(0, precision) + "@" + std::to_string(exp);
    delete[] cstr_result;
    return str_result;
}
