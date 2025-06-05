/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:21:00 by pipolint          #+#    #+#             */
/*   Updated: 2025/04/02 15:45:31 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class	Data
{
	private:
		int	age;
	public:
		Data();
		~Data();
		Data(const Data& obj);
		Data		&operator=(const Data& obj);
		int			getAge() const;
};

#endif