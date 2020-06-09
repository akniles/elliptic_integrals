#include "secondkind.h"

std::string SecondKind::operator()(double k, int set_precision) {
	AGM agm(set_precision);
	MAGM magm(set_precision);
	mpf_t result;
	mpf_t pi;
	mpf_t magm_value;
	mpf_init(result);
	mpf_init(pi);
	mpf_init(magm_value);
	char *cstr_result = new char[set_precision];
	mp_exp_t exp;

	auto str_agm = agm(1, std::sqrt(1 - k * k), 10);
	auto str_magm = magm(1, 1 - k * k, 10);

	mpf_set_str(result, str_agm.c_str(), 10);
	mpf_set_str(magm_value, str_magm.c_str(), 10);
	mpf_mul_ui(result, result, 2);
	mpf_set_str(pi, PI, 10);
    mpf_div(result, pi, result);
    mpf_mul(result, result, magm_value);
    mpf_get_str(cstr_result, &exp, 10, 0, result);

    mpf_clear(result);
    mpf_clear(pi);
    mpf_clear(magm_value);
	std::string str_result(cstr_result);
    return "0." + str_result + "@" + std::to_string(exp);
}
