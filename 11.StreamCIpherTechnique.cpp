#include <iostream>
#include <string>
#include <stdexcept>

int main();
void encrypt_decrypt( std::string &text, std::string const &one_time_pad );

void encrypt_decrypt( std::string &text, std::string const &one_time_pad ) {
	if ( text.length() > one_time_pad.length() ) {
		throw std::length_error( "The message is shorter than the one-time pad." );
	}

	for ( size_t k{0}; k < text.length(); ++k ) {
		text[k] ^= one_time_pad[k];
	}
}

int main() {
	std::string msg{"I am AADI."};

	// 20 randomly chosen characters based on atmospheric noise
	//   - see https://www.random.org/integers/
	//   - this is a null-character terminated string
	char random_numbers[21]{
		  -5,  32, -36, -120,   -8,  -94,   48,   78,  -99,  -92,
		  25,  79,  29,   59,  -41, -108, -127,  -84,   55,   10,
		   0
	};

	std::string one_time_pad{random_numbers};

	std::cout << msg << std::endl;
	encrypt_decrypt( msg, one_time_pad );
	std::cout << msg << std::endl;
	encrypt_decrypt( msg, one_time_pad );
	std::cout << msg << std::endl;

	return 0;
}
