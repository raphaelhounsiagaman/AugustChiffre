#include <iostream>
#include <string>

void encode();
void decode_with_code();
void decode_with_brute_force();

// terrible but sweet little project
// (program gets very mad when it hears ä, ü, ö, ß or other characters that are in the alphabet but not from a to z)

int main()
{
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
		break;
	}
	
	std::cin.ignore();
	std::cin.get();

	main();
	return 0;
}

void encode()
{
restart:
	std::cout << "What would you like your code to be?\n";
	std::cout << "(Must be between 1 and 25)\n";

	int code;
	std::cin >> code;
	if (code < 1 || code > 25)
	{
		std::cerr << "Invalid code. Please try again.\n";
		goto restart;
	}

	std::cout << "What text would you like to encode with code: " << code << "?\n";

	std::string text;
	std::cin.ignore();
	std::getline(std::cin, text);
	
	for (char& c : text)
	{
		if (isalpha(c))
		{
			char base = islower(c) ? 'a' : 'A';
			c = (c - base + code) % 26 + base;
		}
	}

	std::cout << "\nEncoded Text: \n\n" << text << "\n";
	std::cin.ignore();
	std::cin.get();
}

void decode_with_code()
{
restart:
	std::cout << "What's the code of the text you want to decode?\n";
	std::cout << "(Must be between 1 and 25)\n";

	int code;
	std::cin >> code;
	if (code < 1 || code > 25)
	{
		std::cerr << "Invalid code. Please try again.\n";
		goto restart;
	}

	std::cout << "What's the text you want to decode with this code: " << code << "?\n";

	std::string text;
	std::cin.ignore();
	std::getline(std::cin, text);

	for (char& c : text)
	{
		if (isalpha(c))
		{
			char base = islower(c) ? 'a' : 'A';
			c = (c - base - code + 26) % 26 + base;
		}
	}

	std::cout << "\nDecoded Text: \n\n" << text << "\n";
	std::cin.ignore();
	std::cin.get();
}

void decode_with_brute_force()
{
	std::cout << "What's the text you want to decode with brute force?\n";

	std::string text;
	std::cin.ignore();
	std::getline(std::cin, text);

	for (int code = 1; code < 26; code++)
	{
		std::string temp_text = text;
		for (char& c : temp_text)
		{
			if (isalpha(c))
			{
				char base = islower(c) ? 'a' : 'A';
				c = (c - base - code + 26) % 26 + base;
			}
		}

		std::cout << "\nIs this your text?:(code: " << code << ") \n\n" << temp_text << "\n";
		std::cin.ignore();
		std::cin.get();
	}

	std::cout << "\nThese were all the texts\n";
	std::cin.ignore();
	std::cin.get();
}