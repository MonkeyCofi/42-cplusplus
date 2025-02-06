/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:50:50 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/23 20:50:59 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

int	valid_input(std::string &str, int num_check)
{
	if (std::cin.eof())
		return (0);
	size_t	length = str.length();
	if (str.empty() || str.at(0) == '\0' || str.at(0) == '\t' || str.at(0) == '\n')
		return (0);
	if (num_check == 1)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (!(str.at(i) >= '0' && str.at(i) <= '9'))
			{
				std::cout << "\x1b[31m" << "Number is invalid" << "\x1b[0m" << std::endl;
				return (0);
			}
		}
	}
	else if (num_check == 2)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (isspace(str.at(i)))
				continue ;
			if (!(isalpha(str.at(i))))
			{
				std::cout << "\x1b[31m" << "Names can only contain alphabets" << "\x1b[0m" << std::endl;
				return (0);
			}
		}
	}
	return (1);
};
