#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
    	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			int j = 0;
			while (av[i][j])
			{
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					av[i][j] -= 32;
				j++;
			}
			std::cout << av[i];
		}
		std::cout << std::endl;
	}
    return 0;
}