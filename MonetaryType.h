#pragma once

#include <iostream>
#include <utility>

typedef long long int BigInt;

struct MonetaryType {
public:

	MonetaryType();
	MonetaryType(BigInt, BigInt);

	void setValue(BigInt, BigInt);

	std::pair<BigInt, BigInt> getValue();

	friend std::ostream & operator<<(std::ostream &, const MonetaryType &);
	friend std::istream & operator>>(std::istream &, MonetaryType &);

	friend MonetaryType operator+(const MonetaryType &, const MonetaryType &);
	friend MonetaryType operator-(const MonetaryType &, const MonetaryType &);

	friend bool operator==(const MonetaryType &, const MonetaryType &);
	friend bool operator>(const MonetaryType &, const MonetaryType &);
	friend bool operator<(const MonetaryType &, const MonetaryType &);

private:

	BigInt wholePart_;
	BigInt fractionalPart_;

};