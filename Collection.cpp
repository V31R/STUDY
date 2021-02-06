#include "Colletcion.h"

Collection::Collection() {}

Collection::~Collection() {

	for (size_t i{ 0 }; i < wholeData_.size(); i++) {

		delete wholeData_[i];

	}

	for (size_t i{ 0 }; i < dataToOutput_.size(); i++) {

		delete dataToOutput_[i];

	}

}

void Collection::sort(std::vector<PhysicalMoney *> & data, Compare::Property property, Compare::Result result) {

	for (size_t i{ 0 }; i < data.size(); i++) {

		bool isSwapped{ false };

		for (size_t j{ 0 }; j < data.size() - i - 1; j++) {

			if (data[j]->compare(data[j + 1], property) == result) {

				PhysicalMoney * temp{ data[j] };
				data[j] = data[j + 1];
				data[j + 1] = temp;

				isSwapped = true;

			}

		}

		if (!isSwapped) {

			break;

		}

	}

}

void Collection::allocateElement(PhysicalMoney *& element, size_t type) {

	switch (type){

		case 0 : {

			element = new PhysicalMoney;
			break;

		}

		case 1 : {

			element = new Coin;
			break;

		}

		default : {

			element = new PhysicalMoney;
			break;

		}

	}

}

void Collection::copyElement(size_t index) {

	PhysicalMoney * element;

	allocateElement(element, wholeData_[index]->type());

	element->copy(wholeData_[index]);

	dataToOutput_.push_back(element);

}

void Collection::copyData() {

	clearOutputData();

	for (size_t i{ 0 }; i < wholeData_.size(); i++) {

		copyElement(i);

	}

}

void Collection::find(Compare::Property condition, PhysicalMoney * property) {

	clearOutputData();

	for (size_t i{ 0 }; i < wholeData_.size(); i++) {

		if (wholeData_[i]->compare(property, condition) == Compare::Result::EQUAL) {

			copyElement(i);

		}

	}

}

void Collection::output() {

	std::cout << std::endl;
	
	for (size_t i{ 0 }; i < dataToOutput_.size(); i++) {

		dataToOutput_[i]->output(std::cout,false);
		std::cout << std::endl;

	}

	std::cout << std::endl;

}

void Collection::download() {

	std::string dataFileName;

	std::ofstream outputFile{};

	do {

		std::cout << "Enter file name to download\n";
		std::getline(std::cin, dataFileName);
		outputFile.open(dataFileName, std::ios_base::out);

	} while (!outputFile.is_open());

	for (size_t i{ 0 }; i < dataToOutput_.size(); i++) {

		outputFile << dataToOutput_[i]->type() << std::endl;
		dataToOutput_[i]->output(outputFile, true);
		outputFile << std::endl;

	}

	std::cout << "\nDownload to file "<<dataFileName<<" completed successfully.\n\n";

}

void Collection::load() {

	std::string dataFileName;

	std::ifstream inputFile{};

	do {

		std::cout << "Enter file name of collection\n";
		std::getline(std::cin, dataFileName);
		inputFile.open(dataFileName, std::ios_base::in);

	} while (!inputFile.is_open());

	while (!inputFile.eof()) {

		PhysicalMoney * element;

		size_t typeOfElement;

		inputFile >> typeOfElement;

		if (inputFile.eof()) {

			break;

		}

		{
			std::string temp;
			std::getline(inputFile, temp);
		}
		allocateElement(element, typeOfElement);

		element->input(inputFile);

		wholeData_.push_back(element);

	}

	std::cout << "\nFile "<< dataFileName << " loaded succesfuly.\n\n";

}

void Collection::run() {

	load();

	copyData();

	bool isWork{ true };

	while (isWork) {

		Collection::State userChoise;

		for (size_t i{ 0 }; i < Collection::State::NOT_USED_LAST; i++) {

			std::cout << "Enter " << i << " to ";
			outputState(static_cast<Collection::State>(i));
			std::cout << std::endl;

		}

		std::cin >>reinterpret_cast<int &>(userChoise);

		switch (userChoise){

			case Collection::State::OUTPUT : {

				output();
				break;

			}

			case Collection::State::DISCHARGE : {

				copyData();
				break;

			}

			case Collection::State::SORT : {

				std::cout << "Choose property to sort:\n";
				Compare::Property propertyToSort{ chooseProperty() };

				std::cout << "Enter 0 to sort ascending\nEnter 1 to sort descending\n";

				size_t sortCondition;
				std::cin >> sortCondition;

				if (sortCondition == 0) {

					sort(dataToOutput_, propertyToSort, Compare::Result::MORE_ON_THE_LEFT);

				}
				else {

					sort(dataToOutput_, propertyToSort, Compare::Result::LESS_ON_THE_LEFT);

				}

				break;

			}

			case Collection::State::FIND : {

				std::cout << "Choose property to find:\n";
				Compare::Property propertyToFind{ chooseProperty() };

				PhysicalMoney * element;
				makeObjectToFind(element, propertyToFind);

				find(propertyToFind, element);

				delete element;

				break;

			}
			
			case Collection::State::DOWNLOAD: {

				std::string skip;
				std::getline(std::cin,skip);
				download();
				break;

			}

			case Collection::State::END_WORK : {

				isWork = false;
				break;

			}

			default : {
				isWork = false;
				break;

			}

		}
	}

}

void Collection::outputState(Collection::State state) {

	switch (state) {

		case Collection::State::END_WORK: {

			std::cout << "exit the program";
			break;

		}

		case Collection::State::OUTPUT: {

			std::cout << "output current list";
			break;

		}

		case Collection::State::DISCHARGE: {

			std::cout << "discharge this list";
			break;

		}

		case Collection::State::SORT : {

			std::cout << "sort this list by property";
			break;

		}

		case Collection::State::FIND : {

			std::cout << "find element('s) with property";
			break;

		}

		case Collection::State::DOWNLOAD: {

			std::cout << "download current list";
			break;

		}

	}
}

Compare::Property Collection::chooseProperty() {

	Compare::Property property;

	for (size_t i{ 0 }; i < Compare::Property::NOT_USED_LAST; i++) {

		std::cout << "Enter " << i << " to choose ";
		Compare::outputProperty(static_cast<Compare::Property>(i));
		std::cout << std::endl;

	}

	std::cin >> reinterpret_cast<int &>(property);

	return property;

}

void Collection::clearOutputData() {

	for (size_t i{ 0 }; i < dataToOutput_.size(); i++) {

		delete dataToOutput_[i];

	}

	dataToOutput_.clear();

}

void Collection::makeObjectToFind(PhysicalMoney *& element, Compare::Property property) {

	std::cout << "Enter ";
	Compare::outputProperty(property);
	std::cout << std::endl;

	switch (property) {

		case Compare::Property::FACE_VALUE : {

			element = new PhysicalMoney;

			MonetaryType faceValue;
			std::cin >> faceValue;

			element->setFaceValue(faceValue);

			break;

		}

		case Compare::Property::CURRENCY_DESIGNATION : {

			element = new PhysicalMoney;

			Currency currency;
			std::string desigantion;
			{
				std::string temp;
				std::getline(std::cin, temp);
			}
			std::getline(std::cin, desigantion);

			currency.setDesignation(desigantion);

			element->setCurrency(currency);

			break;

		}

		case Compare::Property::COUNTRY : {

			element = new PhysicalMoney;

			Currency currency;
			std::string country;
			{
				std::string temp;
				std::getline(std::cin, temp);
			}
			std::getline(std::cin, country);

			currency.setCountry(country);

			element->setCurrency(currency);

			break;

		}

		case Compare::Property::YEAR_OF_ISSUE : {

			element = new PhysicalMoney;

			Currency currency;
			BigInt year;
			std::cin >> year;

			element->setYear(year);

			break;

		}
		
		case Compare::Property::COST : {

			element = new Coin;
			
			MonetaryType cost;
			std::cin >> cost;
			Money money;
			money.setFaceValue(cost);

			reinterpret_cast<Coin *>(element)->setCost(money);

			break;

		}

		case Compare::Property::MINT : {

			element = new Coin;

			std::string mint;
			{
				std::string temp;
				std::getline(std::cin, temp);
			}
			std::getline(std::cin, mint);
			
			reinterpret_cast<Coin *>(element)->setMint(mint);

			break;

		}

	}

}