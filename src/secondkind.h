#ifndef EINTEGRALS_SECONDKIND_H
#define EINTEGRALS_SECONDKIND_H

#include "agm.h"
#include "magm.h"

class SecondKind {
public:
	SecondKind() = default;

	~SecondKind() = default;

	std::string operator()(double k, int set_precision);
};

#endif // EINTEGRALS_SECONDKIND_H