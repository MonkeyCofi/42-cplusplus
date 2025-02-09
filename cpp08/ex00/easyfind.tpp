template <class T>
T	easyfind(T container, int to_find)
{
	// go through every element of the container (presumably using an iterator)
	// if to_find is found within the container, return it
	// else throw an exception
	class T::const_iterator	it = container.begin();
	while (it != container.end())
	{
		if (to_find == *it)
			return (*it);
		it++;
	}
	throw std::exception();
}