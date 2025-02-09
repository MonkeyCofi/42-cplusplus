/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:28:35 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/08 12:23:12 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// default constructor
template <class T>
Array<T>::Array()
{
	this->m_size = 0;
	this->m_array = NULL;
}

// paramtereized constructor
template <class T>
Array<T>::Array(unsigned int n)
{
	if (n > 0)
	{
		m_size = n;
		this->m_array = new T[n];
	}
}
// destructor
template <class T>
Array<T>::~Array()
{
	if (m_size > 0)
	{
		delete [] this->m_array;
		this->m_array = NULL;
	}
}
// copy constructor
template <class T>
Array<T>::Array(const Array<T>& obj)
{
	this->m_size = obj.m_size;
	this->m_array = new T[this->m_size];
	for (int i = 0; i < this->m_size; i++)
		this->m_array[i] = obj.m_array[i];
}

// assignment operator
template <class T>
Array<T>	&Array<T>::operator=(const Array<T>& obj)
{
	this->m_size = obj.m_size;
	Array<T>*	newArr = new T[obj.m_size];
	for (int i = 0; i < this->m_size; i++)
		newArr[i] = obj.m_array[i];
	delete [] this->m_array;
	this->m_array = newArr;
	return (*this);
}

template <class T>
unsigned int	Array<T>::size() const
{
	return (this->m_size);
}
