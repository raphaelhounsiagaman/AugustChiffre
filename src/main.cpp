#include <iostream>
#include <string>

void encode();
void decode_with_code();
void decode_with_brute_force();

int main()
{
start:

	std::cout << "Choose an action:\n";
	std::cout << "1. Encode\n";
	std::cout << "2. Decode with code\n";
	std::cout << "3. Decode with brute force\n";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		encode();
		break;
	case 2:
		decode_with_code();
		break;
	case 3:
		decode_with_brute_force();
		break;
	default:
		std::cerr << "Invalid choice. Please try again.\n";
		goto start;
		break;
	}
	
	int pause;
	std::cin >> pause;
	return 0;
}

void encode()
{
	std::cout << "What would you like your code to be?\n";
	std::cout << "(Must be between 0 and 25)\n";

	int code;
	std::cin >> code;
}

void decode_with_code()
{

}

void decode_with_brute_force()
{

}