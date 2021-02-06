#pragma once

#include <string>
#include <iostream>


struct Currency {
public:

	Currency();
	Currency(std::string, std::string);

	void setCountry(std::string);
	void setDesignation(std::string);

	std::string getCountry();
	std::string getDesignation();

	std::string getCountry()const;
	std::string getDesignation()const;

	friend std::istream & operator>>(std::istream &, Currency &);

private:

	std::string designation_;
	std::string country_;

};