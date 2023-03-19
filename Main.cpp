#include <iostream>
#include "Read.h"
#include "Calcul.h"


int main() {
	std::string message{""}, polinom{""}, extendedMessage{""}, finalMessage{""};
	if (read_data(message, polinom)) {
		std::cout << "M: " << message << std::endl;
		std::cout << "C: " << polinom << std::endl;
		extendedMessage = extend_message (message, polinom);
		std::cout << "T: " << extendedMessage << std::endl;
		std::cout << "------------------------------" << std::endl;
		finalMessage = message + calcul_XoR(extendedMessage, polinom);
		std::cout << "F: " << finalMessage << std::endl;
	}
	else {
		std::cout << "Errors during execution.";
	}
	
	return 0;
}