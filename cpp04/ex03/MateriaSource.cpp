/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:02:15 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/23 20:08:58 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->m_materias = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		m_materias[i] = NULL;
};

MateriaSource::~MateriaSource()
{
	if (this->m_materias)
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_materias[i])
				delete m_materias[i];
		}
		delete [] m_materias;
		std::cout << RED <<  "Deleted MateriaSource materias" << RESET << std::endl;
	}
	std::cout << RED << "Destructor for MateriaSource was called" << RESET << std::endl;
};

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	this->m_materias = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->m_materias[i] = obj.m_materias[i]->clone();
};

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	this->m_materias = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->m_materias[i] = obj.m_materias[i]->clone();
	return (*this);
};

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;
	while (m_materias[i] != NULL)
		i++;
	if (i == 4)
	{
		std::cout << "Materias are full" << std::endl;
		return ;
	}
	m_materias[i] = m;
	//std::cout << "Learned materia: " << m_materias[i]->getType() << std::endl;
};

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	int i = 0;
	while (m_materias[i] != NULL)
	{
		if (m_materias[i]->getType() == type)
			return (m_materias[i]->clone());
		i++;
	}
	return (0);
};
