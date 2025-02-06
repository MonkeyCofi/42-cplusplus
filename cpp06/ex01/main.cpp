/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:14:53 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/26 19:08:58 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main(void)
{
	Data	data;
	std::cout << "Original data: " << data.getNum() << "\n";
	uintptr_t	raw = Serialize::serialize(&data);
	Data		*recovered = Serialize::deserialize(raw);
	if (recovered == reinterpret_cast<Data*>(raw))
		std::cout << "Addresses are the same\n";
	else
		std::cout << "Addresses are different\n";
	std::cout << "Recovered: " << recovered->getNum() << "\n";
}