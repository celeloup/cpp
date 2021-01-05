#include <iostream>
#include "Pony.hpp"

void	ponyOnTheHeap()
{
	Pony *heap_pony = new Pony("Joe", "apples");
	heap_pony->talk();
	delete heap_pony;
}

void	ponyOnTheStack()
{
	Pony stack_pony("Bella", "grass");
	stack_pony.talk();
}

int		main(void)
{
	std::cout << "** Pony allocated on the heap **" << std::endl;
	ponyOnTheHeap();
    std::cout << std::endl;

    std::cout << "** Pony allocated on the stack **" << std::endl;
    ponyOnTheStack();
}