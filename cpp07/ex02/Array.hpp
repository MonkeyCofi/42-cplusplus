/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:06:19 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/28 14:27:07 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

template<class T>
class	Array
{
	private:
		unsigned int	m_size;
		T*				m_array;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array& arr);
		unsigned int	size(void) const;
		const T			&operator[](unsigned int index) const;
		Array			&operator=(const Array& arr);
		T				&operator[](unsigned int index);
};

# include "Array.tpp"

#endif