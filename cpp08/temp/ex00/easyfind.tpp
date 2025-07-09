#include "easyfind.hpp"

template <class T>
typename T::iterator	easyfind(T& container, int to_find)
{
	typename T::iterator res = std::find(container.begin(), container.end(), to_find);

	if (res == container.end())
		throw (std::invalid_argument("Parameter not found"));
	return (res);
}
