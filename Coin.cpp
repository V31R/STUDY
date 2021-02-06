#include "Coin.h"
void Coin::setCost(const Money & cost) {

	cost_ = cost;

}

void Coin::setMint(std::string mint) {

	mint_ = mint;

}

Money Coin::getCost() {

	return cost_;

}

std::string Coin::getMint() {

	return mint_;

}

Money Coin::getCost()const {

	return cost_;

}


std::string Coin::getMint()const {

	return mint_;

}

std::ostream & operator<<(std::ostream & out, const Coin & coin) {

	out << static_cast<PhysicalMoney>(coin) << " Country: [" << coin.currency.getCountry() << "] Mint: [" << coin.mint_ << "] Cost " 
		<< coin.cost_<<" "<<coin.cost_.getCurrency().getCountry();
	return out;

}

std::istream & operator>>(std::istream & in, Coin & coin) {

	in >> dynamic_cast<PhysicalMoney &>(coin);
	{
		std::string temp;
		std::getline(in, temp);
	}
	std::getline(in, coin.mint_);
	in >> coin.cost_;

	return in;

}

void Coin::output(std::ostream & out, bool isFile = false) {
	if (isFile) {

		static_cast<PhysicalMoney>(*this).output(out, isFile);
		out << mint_ << std::endl;
		cost_.output(out, isFile);

	}
	else {

		out << *this;

	}

}

void Coin::input(std::istream & in) {

	in >> *this;

}

Compare::Result Coin::compare(const PhysicalMoney * physicalMoney, Compare::Property compareCondition) {

	Compare::Result compareResult{ static_cast<PhysicalMoney>(*this).compare(physicalMoney, compareCondition) };

	if (compareResult == Compare::Result::NOT_COMPARABLE) {

		switch (compareCondition) {

			case Compare::Property::COST : {

				compareResult = Compare::compareMonetaryType(cost_.getFaceValue(), reinterpret_cast<const Coin*>(physicalMoney)->cost_.getFaceValue());
				break;

			}

			case Compare::Property::MINT : {

				compareResult = Compare::compareString(mint_, (reinterpret_cast<const Coin*>(physicalMoney)->mint_));
				break;

			}

			default : {

				compareResult = Compare::Result::NOT_COMPARABLE;
				break;

			}

		}

	}

	return compareResult;

}

size_t Coin::type() {

	return 1;

}

void Coin::copy(PhysicalMoney * physicalMoney) {

	*this = *reinterpret_cast<Coin *>(physicalMoney);

}