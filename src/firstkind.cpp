#include "firstkind.h"

std::string FirstKind::operator()(double k, int set_precision) {
	AGM agm(set_precision);
	mpf_t result;
	mpf_t pi;
	mpf_init(result);
	mpf_init(pi);
	auto agm_value = agm(1, std::sqrt(1 - k * k), 10);
	char *cstr_result = new char[set_precision];
	mp_exp_t exp;

	mpf_set_str(result, agm_value.c_str(), 10);
	mpf_mul_ui(result, result, 2);

	mpf_set_str(pi, PI, 10);
    mpf_div(result, pi, result);
    mpf_get_str(cstr_result, &exp, 10, 0, result);
    mpf_clear(pi);
    mpf_clear(result);
	std::string str_result(cstr_result);
    str_result = "0." + str_result + "@" + std::to_string(static_cast<int>(exp));
    return str_result;
}
