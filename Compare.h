#pragma once

#include <string>
#include <iostream>

#include "MonetaryType.h"

struct Compare {
public:

	enum Property { FACE_VALUE, CURRENCY_DESIGNATION, COUNTRY, YEAR_OF_ISSUE, COST, MINT, NOT_USED_LAST};

	enum Result { NOT_COMPARABLE, EQUAL, MORE_ON_THE_LEFT, LESS_ON_THE_LEFT };

	static Compare::Result compareString(std::string, std::string);

	static Compare::Result compareMonetaryType(const MonetaryType &, const MonetaryType &);

	static Compare::Result compareInt(BigInt, BigInt);

	static void outputProperty(Compare::Property);

};