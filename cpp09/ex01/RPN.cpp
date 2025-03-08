/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:39:33 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/08 18:25:32 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	;
}

RPN::~RPN()
{
	;
}

RPN::RPN(const RPN& obj)
{
	(void)obj;
}

RPN	&RPN::operator=(const RPN& obj)
{
	(void)obj;
	return (*this);
}

void	RPN::fillStack(char *s)
{
	std::string			input;
	std::stack<char>	stack;

	input = s;
	if (input.find_first_not_of("0123456789 \t*+-/") != std::string::npos)
		throw (std::invalid_argument("Error: Invalid character used in expresion"));
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		if ((*it) >= '0' && (*it) <= '9')
		{
			if ((it != input.end()) && (*(it + 1) >= '0' && *(it + 1) <= '9'))
				throw (std::invalid_argument("Error: Numbers cannot be greater than 10"));
			stack.push((*it));
		}
		else	// then operator
		{
			
		}
	}
}