#pragma once

#include <iomanip>

#include "PhysicalMoney.h"


struct Coin : public PhysicalMoney {
public:

	void setCost(const Money &);
	void setMint(std::string);

	Money getCost();
	std::string getMint();

	Money getCost() const;
	std::string getMint() const;

	friend std::ostream & operator<<(std::ostream &, const Coin &);
	friend std::istream & operator>>(std::istream &, Coin &);

	virtual void output(std::ostream &, bool) override;
	virtual void input(std::istream &) override;

	virtual Compare::Result compare(const PhysicalMoney *, Compare::Property);

	virtual size_t type() override;

	virtual void copy(PhysicalMoney *) override;

private:

	Money cost_;
	std::string mint_;

};

