#pragma once

#include <iostream>
#include <iomanip>

#include "MonetaryType.h";
#include "Currency.h"


struct Money {
public:

	Money();
	Money(Currency, MonetaryType);
	Money(Currency);
	Money(MonetaryType);

	void setFaceValue(const MonetaryType &);
	void setCurrency(const Currency &);

	MonetaryType getFaceValue();
	Currency getCurrency();

	MonetaryType getFaceValue()const;
	Currency getCurrency()const;

	friend std::ostream & operator<<(std::ostream &, const Money &);
	friend std::istream & operator>>(std::istream &, Money &);

	virtual void output(std::ostream &, bool);

	
protected:

	Currency currency;
	MonetaryType faceValue;

};