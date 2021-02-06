#include "PhysicalMoney.h"

void PhysicalMoney::setName(std::string name) {

	name_ = name;

}

std::string PhysicalMoney::getName() {

	return name_;

}

std::string PhysicalMoney::getName()const {

	return name_;

}

std::ostream & operator<<(std::ostream & out, const PhysicalMoney & physicalMoney) {

	out << "[" << physicalMoney.name_ << "] " << std::setw(5) << static_cast<Money>(physicalMoney) << " Year of issue: " << physicalMoney.yearOfIssue;
	return out;

}

std::istream & operator>>(std::istream & in, PhysicalMoney & physicalMoney) {

	std::getline(in, physicalMoney.name_);
	in >> dynamic_cast<Money &>(physicalMoney) >> physicalMoney.yearOfIssue;

	return in;

}

void PhysicalMoney::output(std::ostream & out, bool isFile = false) {

	if (isFile) {

		out << name_ << std::endl;
		static_cast<Money>(*this).output(out, isFile);
		out << yearOfIssue << std::endl;

	}
	else {

		out << *this;

	}

}

void PhysicalMoney::input(std::istream & in) {

	in >> *this;

}

void PhysicalMoney::setYear(BigInt year) {

	yearOfIssue = year;

}

BigInt PhysicalMoney::getYear() {

	return yearOfIssue;

}
BigInt PhysicalMoney::getYear() const {

	return yearOfIssue;

}

Compare::Result PhysicalMoney::compare(const PhysicalMoney * physicalMoney, Compare::Property compareCondition) {

	switch (compareCondition) {

		case Compare::Property::FACE_VALUE	: {

			return Compare::compareMonetaryType(faceValue, physicalMoney->faceValue);

		}

		case Compare::Property::CURRENCY_DESIGNATION : {

			return Compare::compareString(currency.getDesignation(), physicalMoney->currency.getDesignation());

		}

		case Compare::Property::COUNTRY : {

			return Compare::compareString(currency.getCountry(), physicalMoney->currency.getCountry());

		}

		case Compare::Property::YEAR_OF_ISSUE : {

			return Compare::compareInt(yearOfIssue, physicalMoney->yearOfIssue);

		}

		default : {

			return Compare::Result::NOT_COMPARABLE;

		}

	}

}

size_t PhysicalMoney::type() {

	return 0;

}

void PhysicalMoney::copy(PhysicalMoney * physicalMoney) {

	*this = *physicalMoney;

}