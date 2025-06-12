/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:44:26 by pipolint          #+#    #+#             */
/*   Updated: 2025/06/12 19:40:22 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib>
# include <string>
# include <iterator>
# include <algorithm>
# include <set>
# include <cmath>

class	PmergeMe
{
	private:
		std::vector<int>	vector;
		std::list<int>		list;
		std::set<int>		set;
		bool				oddSize;
		int					lastElem;
		static long			sequence[];

		template <typename T>
		void	printStructure(T& structure);
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj);
		
		void	fillContainers(const char** args);
		int		size();
		void	printVector();

		long			getJacobsthal(int n);

		void			sortVector();
		void			sortVector(std::vector<int>& winnerIndices);
		void			sortList();

		// utility
		void			printPairs(std::vector< std::pair<int, int> >& print);
		int				binaryInsertSearch(int _toInsert, size_t capIndex, std::vector<int>& searchVector);
		void			reorderLosers(std::vector<int>& winners, 
			std::vector<int>& losers, std::vector<int>& winnerIndices);
		// template <typename T>
		// int	PmergeMe::binaryInsertSearch(int _toInsert, T& container);
};

#endif