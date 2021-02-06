#include "Currency.h"

Currency::Currency() :

	designation_{ std::string {"unknown"} },
	country_{ std::string {"unknown"} }

{}

Currency::Currency(std::string designation, std::string country = "unknown") :

	designation_{ designation },
	country_{ country }

{}

void Currency::setCountry(std::string country) {

	country_ = country;

}

void Currency::setDesignation(std::string designation) {

	designation_ = designation;

}

std::string Currency::getCountry() {

	return country_;

}

std::string Currency::getDesignation() {

	return designation_;

}

std::string Currency::getCountry()const {

	return country_;

}

std::string Currency::getDesignation()const {

	return designation_;

}

std::istream & operator>>(std::istream & in, Currency & currency) {
	
	std::getline(in, currency.designation_);
	std::getline(in, currency.country_);

	return in;

}