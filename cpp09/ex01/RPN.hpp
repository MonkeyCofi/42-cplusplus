/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:53:14 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/13 15:34:19 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

class	RPN
{
	private:
		enum	operators
		{
			unknown = -1,
			add,
			subtract,
			multiply,
			divide
		};
	public:
		RPN();
		~RPN();
		RPN(const RPN& obj);
		RPN	&operator=(const RPN& obj);
		static RPN::operators	returnOperation(char c);
		static double			calculate(char *s);
		
};

#endif
