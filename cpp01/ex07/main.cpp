#include <iostream>
#include <fstream>
#include <string.h>

std::string	replace(std::string line, std::string s1, std::string s2)
{
	std::size_t found;
	found = line.find(s1);
	while (found < line.length())
	{
		line.replace(found, s1.length(), s2);
		found = line.find(s1, found + 1);
	}
	return (line);
}


int main(int ac, char **av)
{
	// TEST USAGE
	if (ac != 4 || av[1][0] == '\0' || av[2][0] == '\0' || av[3][0] == '\0')
	{
		std::cout << "usage: ./replace [filename] [s1] [s2]" << std::endl;
		return (1);
	}

	// OUVERTURE INPUT
	std::ifstream input(av[1]);
	if (!input.is_open())
	{
		std::cout << "Error: Couldn't open file." << std::endl;
		return (1);
	}

	// OUVERTURE OUTPUT
	std::string outputFile = av[1];
	outputFile += ".replace";
	std::ofstream output(outputFile.c_str());
	if (!output.is_open())
	{
		input.close();
		std::cout << "Error: Couldn't produce output file." << std::endl;
		return (1);
	}

	// REPLACING ALGORITHM
	std::string line;
	while (getline(input, line))
	{
		line = replace(line, av[2], av[3]);
		output << line << std::endl;
	}

	input.close();
	output.close();
	return (0);
}