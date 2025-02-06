/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:56:17 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/23 20:08:22 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* cloud = new Character("Cloud");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	cloud->equip(tmp);
	tmp = src->createMateria("cure");
	cloud->equip(tmp);

	ICharacter* sephiroth = new Character("Sephiroth");
	Character temp;

	cloud->use(0, *sephiroth);
	cloud->use(1, *sephiroth);
	cloud->use(2, *sephiroth);

	cloud->unequip(0);
	temp.deleteLastDropped();

	delete sephiroth;
	delete cloud;
	delete src;
}