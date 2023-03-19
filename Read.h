#pragma once
#include <string>
#include <fstream>
#include <ctype.h>
#include <vector>


bool read_data(std::string& message, std::string& C) {
	std::ifstream date;
	std::vector <int> coeficientiPolinom;
	std::string polinom{ "" };

#pragma region Read message
	date.open("Text.txt");
	try {
		std::string errorMessage{ "" };
		if (date.is_open()) {
			while (!date.eof()) {
				char caracter;
				date >> caracter;
				if (caracter == '1' || caracter == '0') {
					message.push_back(caracter);
				}
				else {
					throw (errorMessage = "Invalid input");
				}
			}
		}
		else {
			throw (errorMessage = "Error to open file");
		}
	}
	catch (std::string errorMessage) {
		std::cout << errorMessage << std::endl;
		return false;
	}
	message.pop_back();
	date.close();
#pragma endregion

#pragma region Read Polinom
	date.open("Polinom.txt");
	try {
		std::string errorMessage{ "" };
		if (date.is_open()) {
			date >> polinom;
		}
		else {
			throw (errorMessage = "Error to open file");
		}
	}
	catch (std::string errorMessage) {
		std::cout << errorMessage << std::endl;
		return false;
	}

	//extragere puteri din string
	//48->0 in ASCII
	for (char ch : polinom) {
		if (isdigit(ch)) {
			coeficientiPolinom.push_back(ch - 48);
		}
	}

	for (int i = 0; i <= coeficientiPolinom.at(0); i++) {
		C.push_back('0');
	}

	for (auto el : coeficientiPolinom) { 
		C[C.size() - 1 - el] = '1'; 
	}

	if (coeficientiPolinom[coeficientiPolinom.size() - 1 ==
		coeficientiPolinom[coeficientiPolinom.size() - 2]]) {
		C[C.size() - 1] = '1';
	}

	date.close();
#pragma endregion

	if (message.size() < coeficientiPolinom.size()) {
		std::cout << "Lungimea mesajului este mai mica decat numarul de coeficienti.";
		return false;
	}
	return true;
}