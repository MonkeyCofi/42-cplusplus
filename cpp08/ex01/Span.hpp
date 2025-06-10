/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:32:01 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/19 18:23:38 by pipolint         ###   ########.fr       */
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
		void	addNumber(std::vector<int>::iterator pos, std::vector<int>::iterator _begin, std::vector<int>::iterator _end);
		int		shortestSpan();
		int		longestSpan();
		
		void	printElements();
	
		std::vector<int>::iterator	_begin();
		std::vector<int>::iterator	_end();
		
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