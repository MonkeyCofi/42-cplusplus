/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:20:51 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/27 16:40:10 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <ctime>

template<class T>
void	print_elem(T& elem)
{
	std::cout << elem << "\n";
}

template<class T>
void	set_random(T& elem)
{
	elem = rand() % 16384;
}

template <class T>
void	print_elem(const T& elem)
{
	std::cout << "const: " << elem << "\n";
}

template<class T>
void	increment_elem(T& elem)
{
	elem++;
}

template<class T>
void	half_elem(T& elem)
{
	elem /= 2;
}

template <class T>
void	iter(T* array, int arr_length, void(*func)(T&))
{
	for (int i = 0; i < arr_length; i++)
		func(array[i]);
}

class Person
{
	private:
		std::string	name;
		int 		age;
		Person();
		Person(const Person& person);
		Person	&operator=(const Person& person);
	public:
		Person(std::string name_, int age_): name(name_), age(age_) {std::cout << this->name << "(" << age << " years of age)" << " has been summoned\n";};
		std::string getName() const {return (this->name);};
		int	getAge() const {return (this->age);};
		~Person(){std::cout << this->name << " is done for\n";}; 
};

template <class T>
void	print_person(T& p)
{
	std::cout << p->getName() << " says: Hi. I'm " << p->getAge() << " years old\n";
}

int main(void)
{
	{
		int size = 3;
		int *arr = new int[size]();
		iter(arr, size, set_random);
		iter(arr, size, print_elem);
		iter(const_cast<const int*>(arr), size, print_elem);
	}
	std::cout << "\n";
	{
		Person first("Joe", 42);
		Person second("Alan", 32);
		Person third("Max", 29);
		Person fourth("Nathan", 20);
		Person *people[4] = {&first, &second, &third, &fourth};
		iter(people, 4, print_person);
	}
}
