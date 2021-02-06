#pragma once

#include <iomanip>

#include "Money.h"
#include "Compare.h"


struct PhysicalMoney : public Money {
public:

	void setYear(BigInt year);

	BigInt getYear();
	BigInt getYear()const;

	void setName(std::string);

	std::string getName();
	std::string getName() const;

	friend std::ostream & operator<<(std::ostream &, const PhysicalMoney &);
	friend std::istream & operator>>(std::istream &, PhysicalMoney &);

	virtual void output(std::ostream &, bool) override;
	virtual void input(std::istream &);

	virtual Compare::Result compare(const PhysicalMoney *, Compare::Property);

	virtual size_t type();
	virtual void copy(PhysicalMoney *);

protected:

	BigInt yearOfIssue;
	std::string name_;

};
