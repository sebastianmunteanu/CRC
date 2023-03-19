#pragma once
#include <string>
#include "Xor.h"


std::string extend_message(const std::string& message, const std::string& polinom) {
	std::string msg;
	msg = message;
	for (int i{ 0 }; i < polinom.size() - 1; i++) {
		msg.push_back('0');
	}
	return msg;
}

int getOnePos(std::string extendedMessage) {
	for (int i{ 0 }; i < extendedMessage.size(); i++) {
		if (extendedMessage[i] == '1') {
			return i;
		}
	}
	return NULL;
}

std::string calcul_XoR(std::string extendedMessage, const std::string& polinom) {
	int onePos{ 0 };
	Xor xOr = Xor();
	while (extendedMessage.length() >= polinom.length()) {
		std::cout << extendedMessage << std::endl;
		onePos = getOnePos(extendedMessage);
		if (onePos != 0) {
			for (int i{ 0 }; i < onePos; i++) {
				extendedMessage.erase(extendedMessage.begin(), extendedMessage.begin() + 1);
				std::cout << " ";
			}
		}
		if (extendedMessage.length() < polinom.length()) {
			std::cout << "\r-> " << extendedMessage << std::endl;
			return extendedMessage;
		}

		else {
			std::cout << polinom << std::endl;
		}

		if (onePos != 0) {
			for (int i{ 0 }; i < onePos; i++) {
				std::cout << " ";
			}
		}

		for (int i{ 0 }; i < polinom.size(); i++) {
			extendedMessage[i] = xOr.twoValuesCalc(extendedMessage[i], polinom[i]);
		}
		std::cout << extendedMessage << std::endl;
		std::cout << "-----------------------------" << std::endl;
	}
	return "";
}