#include "Contact.hpp"
#include <iostream>

// CONSTRUCTEURS / DESTRUCTEURS

Contact::Contact()
{  }

Contact::~Contact()
{  }

// METHODES D'INSTANCE

std::string Contact::get_first_name(void)
{  return (this->first_name);  }

std::string Contact::get_last_name(void)
{  return (this->last_name);  }

std::string Contact::get_nickname(void)
{  return (this->nickname); }

void Contact::set_first_name(std::string new_first_name)
{ this->first_name = new_first_name; }

void Contact::set_last_name(std::string new_last_name)
{  this->last_name = new_last_name; }

void Contact::set_nickname(std::string new_nickname)
{  this->nickname = new_nickname;  }

void Contact::set_login(std::string new_login)
{  this->login = new_login;  }

void Contact::set_postal_address(std::string new_postal_address)
{  this->postal_address = new_postal_address;  }

void Contact::set_email_address(std::string new_email_address)
{  this->email_address = new_email_address;  }

void Contact::set_phone_number(std::string new_phone_number)
{  this->phone_number = new_phone_number;  }

void Contact::set_birthday_date(std::string new_birthday_date)
{  this->birthday_date = new_birthday_date;  }

void Contact::set_favorite_meal(std::string new_favorite_meal)
{  this->favorite_meal = new_favorite_meal;  }

void Contact::set_underwear_color(std::string new_underwear_color)
{  this->underwear_color = new_underwear_color;  }

void Contact::set_darkest_secret(std::string new_darkest_secret)
{  this->darkest_secret = new_darkest_secret;  }

bool Contact::is_empty(void)
{
	if (this->first_name == "")
		return (true);
	else
		return (false);
}

void Contact::show(void) const
{
	std::cout << "first name      > " << this->first_name << std::endl;
	std::cout << "last name       > " << this->last_name << std::endl;
	std::cout << "nickname        > " <<  this->nickname << std::endl;
	std::cout << "login           > " << this->login << std::endl;
	std::cout << "postal address  > " << this->postal_address << std::endl;
	std::cout << "email address   > " << this->email_address << std::endl;
	std::cout << "phone number    > " << this->phone_number << std::endl;
	std::cout << "birthday date   > " << this->birthday_date << std::endl;
	std::cout << "favorite meal   > " << this->favorite_meal << std::endl;
	std::cout << "underwear color > " << this->underwear_color << std::endl;
	std::cout << "darkest secret  > " << this->darkest_secret << std::endl;
}
