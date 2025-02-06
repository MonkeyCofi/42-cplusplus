/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:24 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/20 18:49:18 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	Animal **animals = new Animal*[20];
	int i = 0;
	for (; i < 10; i++)
		animals[i] = new Cat();
	for (; i < 20; i++)
		animals[i] = new Dog();
	for (i = 0; i < 20; i++)
		delete animals[i];
	delete [] animals;
	
	std::cout << CYAN << "--------Copy Tests--------" << RESET << std::endl;
	Cat *cat = new Cat();
	Cat *copy = new Cat(*cat);
	std::cout << "Cat Address: " << cat->brainAddress() << std::endl;
	std::cout << "Copy Address: " << copy->brainAddress() << std::endl;
	delete cat;
	delete copy;
}
