#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{

public:
	
	Contact(void);
	~Contact(void);

	std::string get_first_name(void);
	void set_first_name(std::string first_name);
	std::string get_last_name(void);
	void set_last_name(std::string last_name);
	std::string get_nickname(void);
	void set_nickname(std::string nickname);
	void set_login(std::string login);
	void set_postal_address(std::string postal_address);
	void set_email_address(std::string email_address);
	void set_phone_number(std::string phone_number);
	void set_birthday_date(std::string birthday);
	void set_favorite_meal(std::string favorite_meal);
	void set_underwear_color(std::string underwear_color);
	void set_darkest_secret(std::string darkest_secret);
	
	bool is_empty(void);
	void show(void) const;

private:

	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color;
	std::string darkest_secret;
};

#endif