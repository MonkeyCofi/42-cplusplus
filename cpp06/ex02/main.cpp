/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:55:54 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/27 13:34:58 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	time_t	t;
	srand(time(&t));
	int	r = rand() % 3;
	switch(r)
	{
		case (0):
			return (new A);
		case(1):
			return (new B);
		case(2):
			return (new C);
	}
	return (NULL);
}

void	identify(Base* p)
{
	int i = 0;
	switch(i)
	{
		case (0):
		{
			if (dynamic_cast<A*>(p) != NULL)
			{
				std::cout << "Pointer is of type A\n";
				return ;
			}
			i++;
		}
		case (1):
		{
			if (dynamic_cast<B*>(p) != NULL)
			{
				std::cout << "Pointer is of type B\n";
				return ;
			}
			i++;
		}
		case (2):
		{
			if (dynamic_cast<C*>(p) != NULL)
			{
				std::cout << "Pointer is of type C\n";
				return ;
			}
		}
	}
	std::cout << "Pointer is of none of those types\n";
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Reference is of type A\n";
		(void)a;
		return ;
	}
	catch (std::bad_cast)
	{
		
	}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Reference is of type B\n";
		(void)b;
		return ;
	}
	catch (std::bad_cast)
	{
		;
	}

	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Reference is of type C\n";
		(void)c;
		return ;
	}
	catch (std::bad_cast)
	{
		;
	}
}

int main(void)
{
	Base*	p = generate();
	identify(p);
	identify(*p);
}