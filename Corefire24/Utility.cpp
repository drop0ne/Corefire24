#include "Utility.h"
#include "include.h"

inline void Utility::clearInputStream() {
	std::cin.clear();
	if (std::cin.rdbuf()->in_avail() > 0) {
		// If there are characters in the input buffer, discard them up to the next newline
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
inline void Utility::extractInputStream() {
	std::cout << "Contents of input stream: ";
	char c;
	while (std::cin.peek() != EOF) {
		std::cin.get(c);
		std::cout << c;
	}
	std::cout << std::endl;
	return;
}
