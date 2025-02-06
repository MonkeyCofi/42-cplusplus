#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

class	ElementNotFoundException
{
	public:
		const char*	what();
};

template <class T>
T	easyfind(T container, int to_find);

# include "easyfind.tpp"

#endif