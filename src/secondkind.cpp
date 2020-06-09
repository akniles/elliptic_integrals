#include "secondkind.h"

std::string SecondKind::operator()(double k, size_t precision) {
	size_t mpf_precision = 5 * precision;
    mpf_set_default_prec(mpf_precision);
    size_t int_base = 10;

	AGM agm;
	MAGM magm;
	mpf_t result;
	mpf_t pi;
	mpf_t magm_value;
	mpf_init(result);
	mpf_init(pi);
	mpf_init(magm_value);
	char *cstr_result = new char[mpf_precision];
	mp_exp_t exp;

	auto str_agm = agm(1, std::sqrt(1 - k * k), mpf_precision);
	auto str_magm = magm(1, 1 - k * k, mpf_precision);

	mpf_set_str(result, str_agm.c_str(), int_base);
	mpf_set_str(magm_value, str_magm.c_str(), int_base);
	mpf_mul_ui(result, result, 2);
	mpf_set_str(pi, CalculatePi(mpf_precision).c_str(), int_base);
    mpf_div(result, pi, result);
    mpf_mul(result, result, magm_value);
    mpf_get_str(cstr_result, &exp, int_base, mpf_precision, result);

    mpf_clear(result);
    mpf_clear(pi);
    mpf_clear(magm_value);
	std::string str_result(cstr_result);
    str_result = "0." + str_result.substr(0, precision) + "@" + std::to_string(exp);
	delete[] cstr_result;
    return str_result;
}
