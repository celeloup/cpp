#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *str_ptr = &str;
	std::string &str_ref = str;
	std::cout << "Ptr = " << *str_ptr << std::endl;
	std::cout << "Ref = " << str_ref << std::endl;
	return (0);
}