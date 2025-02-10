/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:32:01 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/10 14:08:54 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iostream>
# include <vector>

class Span
{
	private:
		unsigned int 		N;
		std::vector<int>	numbers;
	public:
		Span();
		~Span();
		Span(const Span& obj);
		Span	&operator=(const Span& obj);

		Span(unsigned int N);
		void	addNumber(int number);
		void	addNumber(std::vector<int> _start, std::vector<int> _end, int valuetest);
		int		shortestSpan();
		int		longestSpan();
		
		void	printElements();
		
		class	VectorFullException
		{
			public:
				const char*	what();
		};
		
		class	NoElementsException
		{
			public:
				const char*	what();
		};
		
		class	OneElementException
		{
			public:
				const char*	what();
		};
};

#endif