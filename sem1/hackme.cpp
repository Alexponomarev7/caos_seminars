#include <iostream>

int main() {
	std::cout << "Password:" << std::endl;
	
	int password;
	std::cin >> password;
	if (password == 1234) {
		std::cout << "You win!" << std::endl;
	} else {
		std::cout << "You lose!" << std::endl;
	}
}
