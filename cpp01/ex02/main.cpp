/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:24:56 by pipolint          #+#    #+#             */
/*   Updated: 2024/08/29 16:52:06 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "String's memory: " << &str << std::endl;
	std::cout << "Pointer to the string: " << stringPTR << std::endl;
	std::cout << "Reference to the string: " << &stringREF << std::endl;
	
	std::cout << "String's value: " << str << std::endl;
	std::cout << "Pointer's value: " << *stringPTR << std::endl;
	std::cout << "Reference's value: " << stringREF << std::endl;
}