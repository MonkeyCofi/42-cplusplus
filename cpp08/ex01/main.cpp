/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:37:27 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/10 09:46:48 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	Span s(5);
	try
	{
		
		//s.addNumber(1);
		//s.addNumber(2);
		//s.addNumber(3);
	}
	catch (Span::VectorFullException& ex)
	{
		std::cout << ex.what() << "\n";
	}
	s.printElements();
}