#include "easyfind.hpp"
#include <list>

const char*	ElementNotFoundException::what()
{
	return "Element not found within container\n";
}

int main(void)
{
	std::list<int>arr;
	for (int i = 0; i < 5; i++)
		arr.push_back(i + 1);
	int found = easyfind(arr, 6);
}