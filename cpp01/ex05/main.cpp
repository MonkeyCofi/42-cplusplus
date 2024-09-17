/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:30:19 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/01 14:43:35 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	george;
	george.complain("DEBUG");
	george.complain("INFO");
	george.complain("WARNING");
	george.complain("ERROR");
	george.complain("CHEESEBURGER");
}
