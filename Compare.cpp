#include "Compare.h"

Compare::Result Compare::compareString(std::string left, std::string right) {

	int compareResult{ left.compare(right) };

	if (compareResult == 0) {

		return Compare::Result::EQUAL;

	}
	else if (compareResult > 0) {

		return Compare::Result::MORE_ON_THE_LEFT;

	}

	return Compare::Result::LESS_ON_THE_LEFT;

}

Compare::Result Compare::compareMonetaryType(const MonetaryType & left, const MonetaryType & right) {

	if (left == right) {

		return Compare::Result::EQUAL;

	}
	else if (left > right) {

		return Compare::Result::MORE_ON_THE_LEFT;

	}

	return Compare::Result::LESS_ON_THE_LEFT;

}

Compare::Result Compare::compareInt(BigInt left, BigInt right) {

	if (left == right) {

		return Compare::Result::EQUAL;

	}
	else if (left > right) {

		return Compare::Result::MORE_ON_THE_LEFT;

	}

	return Compare::Result::LESS_ON_THE_LEFT;

}

void Compare::outputProperty(Compare::Property conditionType) {

	switch (conditionType) {

		case Compare::Property::FACE_VALUE : {

			std::cout << "face value";
			break;

		}

		case Compare::Property::CURRENCY_DESIGNATION : {

			std::cout << "currency designation";
			break;

		}

		case Compare::Property::COUNTRY : {

			std::cout << "country";
			break;

		}

		case Compare::Property::YEAR_OF_ISSUE : {

			std::cout << "year of issue";
			break;

		}

		case Compare::Property::COST : {

			std::cout << "cost";
			break;

		}

		case Compare::Property::MINT : {

			std::cout << "mint";
			break;

		}

	}

}