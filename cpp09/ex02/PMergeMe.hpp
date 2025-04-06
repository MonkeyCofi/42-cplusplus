/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:44:26 by pipolint          #+#    #+#             */
/*   Updated: 2025/04/06 16:10:21 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib>
# include <string>
# include <iterator>
# include <algorithm>

class	PMergeMe
{
	private:
		std::vector<int>	vector;
		std::list<int>		list;
	public:
		PMergeMe();
		~PMergeMe();
		PMergeMe(const PMergeMe& obj);
		PMergeMe	&operator=(const PMergeMe& obj);
		
		void	fillContainers(const char** args);
		int		size();
		
		static int			calculateJacobsthal(int nthJacobsthal);
		static unsigned int	binarySearchVector(std::vector<int>& _vector, unsigned int low, unsigned int high, int valToInsert);

		void			sortVector();
		void			sortList();
		void			printVector();
		void			printVector(std::vector<int>& _vector);
		void			printPairs(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		// unsigned int	binarySearchVector(unsigned int start, unsigned int middle, unsigned int end, int valToInsert);
		void			insertRemaining(std::vector<int>& mainChain, std::vector<int>& appendChain, unsigned int lastInsertedIndex);
		
		void			jacobsthalInsert(int jacobsthalNumber, unsigned int& appendageCount, std::vector<int>& mainChain, std::vector< std::pair<int,int> >& pairElements);
		void			binaryInsert(std::vector<int>& mainChain, std::vector< std::pair<int,int> >& pairElements);
		
		void			recurseVector(int pairSize);
		
		void				sortVector(std::vector<int>& _vec);
		void				mergeInsertionSort(std::vector<int>& _winners, std::vector<int>& _losers);
		std::vector<int>	swapPairs(std::vector<int>& to_sort);
		std::vector<int>	returnWinners(std::vector<int>& _vec);
		std::vector<int>	returnLosers(std::vector<int>& _vec);
};

#endif