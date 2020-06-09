#include "agm.h"

std::string AGM::operator()(double a, double b, int iters) {
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
    char *result = new char[precision];
    mp_exp_t exp;
    mpf_get_str(result, &exp, 10, 0, x);
    mpf_set_ui(x, 0);
    mpf_set_ui(y, 0);
    mpf_clear(x_next);
    mpf_clear(y_next);
    std::string str_result(result);
    str_result = "0." + str_result + "@" + std::to_string(static_cast<int>(exp));
    return str_result;
}

AGM::AGM(int set_precision) {
    precision = set_precision;
    mpf_set_default_prec(precision);
    mpf_init(x);
    mpf_init(y);
    mpf_set_ui(x, 0);
    mpf_set_ui(y, 0);
}

AGM::~AGM() {
    mpf_clear(x);
    mpf_clear(y);
}
