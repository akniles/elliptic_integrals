#ifndef EINTEGRALS_FIRSTKIND_H
#define EINTEGRALS_FIRSTKIND_H

#include "agm.h"

class FirstKind {
public:
	FirstKind() = default;

	~FirstKind() = default;

	std::string operator()(double k, int set_precision);
};

#endif // EINTEGRALS_FIRSTKIND_H