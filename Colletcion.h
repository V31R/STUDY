#pragma once

#include <vector>
#include <iostream>
#include <fstream>

#include "PhysicalMoney.h"
#include "Coin.h"

struct Collection {
public:

	enum State {END_WORK, OUTPUT, DISCHARGE, SORT, FIND, DOWNLOAD, NOT_USED_LAST};

	Collection();
	~Collection();

	void load();
	void download();

	void sort(std::vector<PhysicalMoney *> &, Compare::Property, Compare::Result);
	void find(Compare::Property, PhysicalMoney *);

	void output();

	void run();

private:

	void allocateElement(PhysicalMoney *&, size_t);

	void copyElement(size_t);
	void copyData();

	void clearOutputData();
	void makeObjectToFind(PhysicalMoney *&, Compare::Property);
	void outputState(Collection::State);

	Compare::Property chooseProperty();

	std::vector<PhysicalMoney *> wholeData_;
	std::vector<PhysicalMoney *> dataToOutput_;

};
