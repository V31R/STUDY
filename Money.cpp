#include "Money.h"

Money::Money():

	currency{},
	faceValue{}

{}

Money::Money(MonetaryType _faceValue) :

	currency{},
	faceValue{_faceValue}

{}

Money::Money(Currency _currency):

	currency{ _currency },
	faceValue{}

{}

Money::Money(Currency _currency, MonetaryType _faceValue) :

	currency{ _currency },
	faceValue{ _faceValue }

{}

void Money::setFaceValue(const MonetaryType & _faceValue) {

	faceValue = _faceValue;

}

void Money::setCurrency(const Currency & _currency) {

	currency = _currency;

}

MonetaryType Money::getFaceValue() {

	return faceValue;

}

MonetaryType Money::getFaceValue()const {

	return faceValue;

}

Currency Money::getCurrency() {

	return currency;

}

Currency Money::getCurrency() const{

	return currency;

}

std::ostream & operator<<(std::ostream & out, const Money & money) {

	out << money.faceValue << std::setw(3)<<" " << money.currency.getDesignation();
	return out;

}
std::istream & operator>>(std::istream & in, Money & money) {

	in >> money.faceValue;
	{
		std::string temp;
		std::getline(in, temp);
	}
	in >> money.currency;

	return in;

}

void Money::output(std::ostream & out, bool isFile = false) {

	if (isFile) {

		out << faceValue << std::endl << currency.getDesignation()<<std::endl<<currency.getCountry()<<std::endl;

	}
	else {

		out << *this;

	}

}