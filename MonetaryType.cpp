#include "MonetaryType.h"
MonetaryType::MonetaryType() :

	wholePart_{ 0LL },
	fractionalPart_{ 0LL }

{}
MonetaryType::MonetaryType(BigInt wholePart, BigInt fractionalPart = 0LL) :

	wholePart_{ wholePart },
	fractionalPart_{ fractionalPart }

{}

std::pair<BigInt, BigInt> MonetaryType::getValue() {

	return std::pair<BigInt, BigInt> { wholePart_, fractionalPart_ };

}

void MonetaryType::setValue(BigInt wp = 0, BigInt fp = 0) {

	wholePart_ = wp;
	fractionalPart_ = fp;

}

MonetaryType operator+(const MonetaryType & left, const MonetaryType & right) {

	MonetaryType result{ left.wholePart_ + right.wholePart_ };

	if (BigInt sum{ left.fractionalPart_ + right.fractionalPart_ }; sum > 100) {

		result.wholePart_++;
		result.fractionalPart_ = sum - 100;

	}
	else {

		result.fractionalPart_ = sum;

	}

	return result;

}

MonetaryType operator-(const MonetaryType & left, const MonetaryType & right) {

	MonetaryType result{ left.wholePart_ - right.wholePart_ };

	if (BigInt diff{ left.fractionalPart_ - right.fractionalPart_ }; diff < 0) {
		result.wholePart_--;
		result.fractionalPart_ = 100 + diff;
	}
	else {
		result.fractionalPart_ = diff;
	}

	return result;

}

std::ostream & operator<<(std::ostream & out, const MonetaryType & value) {

	out << value.wholePart_ << ".";

	if (value.fractionalPart_ < 10) {

		out << "0";

	}

	out << value.fractionalPart_;

	return out;

}

std::istream & operator>>(std::istream & in, MonetaryType & value) {

	char c{ 0 };
	in >> value.wholePart_ >> c >> value.fractionalPart_;
	return in;

}

bool operator==(const MonetaryType & left, const MonetaryType & right) {

	return (left.wholePart_ == right.wholePart_) && (left.fractionalPart_ == right.fractionalPart_);

}

bool operator>(const MonetaryType & left, const MonetaryType & right) {

	return (left.wholePart_ > right.wholePart_) ||
		((left.wholePart_ == right.wholePart_) && (left.fractionalPart_ > right.fractionalPart_));

}

bool operator<(const MonetaryType & left, const MonetaryType & right) {

	return (left.wholePart_ < right.wholePart_) ||
		((left.wholePart_ == right.wholePart_) && (left.fractionalPart_ < right.fractionalPart_));

}
