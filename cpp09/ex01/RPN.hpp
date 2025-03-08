/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:53:14 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/08 18:23:22 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class	RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN& obj);
		RPN	&operator=(const RPN& obj);
		static void	fillStack(char *s);
};

#endif
