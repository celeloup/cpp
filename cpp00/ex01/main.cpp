#include <iostream>
#include <string.h>
#include <algorithm>
#include "Contact.hpp"

void add_contact(Contact list[8])
{
	int index = 0;
	while (list[index].is_empty() == false)
		index++;
	if (index == 8)
	{
		std::cout << "\e[2;31m  [phonebook is full ! :(]\e[0m" << std::endl;
		return ;
	}
	std::cout << "\e[2m[adding a contact ...]\e[0m" << std::endl;
	std::string labels[11] =
	{
		"first name",
		"last name",
		"nickname",
		"login",
		"postal address",
		"email",
		"phone number",
		"birthday date",
		"favorite meal",
		"underwear color",
		"darkest secret"
	};
	int i = 0;
	std::string input;
	while (i < 11)
	{
		std::cout << "  " << labels[i] << " : ";
		std::getline(std::cin, input);
		if (input == "")
		{
			std::cout << "\e[0;31m[no empty è_é]\e[0m" << std::endl;
			continue;
		}
		switch ( i )
		{	
			case 0:
				list[index].set_first_name(input);
				break;
			case 1:
				list[index].set_last_name(input);
				break;
			case 2:
				list[index].set_nickname(input);
				break;
			case 3:
				list[index].set_login(input);
				break;
			case 4:
				list[index].set_postal_address(input);
				break;
			case 5:
				list[index].set_email_address(input);
				break;
			case 6:
				list[index].set_phone_number(input);
				break;
			case 7:
				list[index].set_birthday_date(input);
				break;
			case 8:
				list[index].set_favorite_meal(input);
				break;
			case 9:
				list[index].set_underwear_color(input);
				break;
			case 10:
				list[index].set_darkest_secret(input);
				break;
		}
		i++;
	}
	std::cout << "\e[2m[contact added !]\e[0m" << std::endl;
}

void format(std::string to_format)
{
	if (to_format.length() > 10)
	{
		to_format = to_format.insert(9, ".");
		to_format = to_format.substr(0, 10);
	}
	else
	{
		while (to_format.length() < 10)
            to_format = to_format.insert(0, " ");
	}
	std::cout << to_format;
}

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void search(Contact list[8])
{
	std::cout << std::endl << "\e[1m       index|first name| last name|  nickname" << std::endl;
    std::cout << "  -------------------------------------------\e[0m" << std::endl;
	int i = 0;
	while (!list[i].is_empty() && i < 8)
	{
		std::cout << "         " << i << "|";
        format(list[i].get_first_name());
        std::cout << "|";
        format(list[i].get_last_name());
        std::cout << "|";
        format(list[i].get_nickname());
        std::cout << std::endl;
		i++;
	}
	if (i > 0)
	{
		std::string input;
		std::cout << std::endl;
		std::cout << "\e[2m  Index of contact to display > \e[0m";
		std::getline(std::cin, input);
		std::cout << std::endl;
		if (input != "")
		{
			int index = atoi(input.c_str());
			if (is_number(input) && index >= 0 && index < 8 && !list[index].is_empty())
			{
				std::cout << "\e[1m  Contact n°" << index << " aka " << list[index].get_nickname() << "\e[0m" << std::endl;
				list[index].show();
			}
			else
				std::cout << "\e[0;31m  [no contact found for entry]\e[0m" << std::endl;
		}
	}
	else
		std::cout << "\t     \e[2m[phonebook is empty]\e[0m" << std::endl;
	std::cout << std::endl;
}

int main()
{
    Contact phonebook[8];
    std::string request;
	std::cout << "\t \e[1;34mPhonebook\e[0m" << std::endl;
	while (1)
	{
		std::cout << "\e[1;33mPHONEBOOK\e[0m > ";
		std::getline(std::cin, request);
		if (request == "EXIT")
		{
			std::cout << "\e[2m[phonebook will miss u </3]\e[0m" << std::endl;
			return (0);
		}	
		else if (request == "ADD")
			add_contact(phonebook);
		else if (request == "SEARCH")
			search(phonebook);
	}
    return 0;
}