/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:44:26 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/24 15:12:00 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib>
# include <string>
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
		
		static int		calculateJacobsthal(int nthJacobsthal);
		void			sortVector();
		void			sortList();
		void			printVector();
		void			printVector(std::vector<int>& _vector);
		void			printPairs(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		// unsigned int	binarySearchVector(unsigned int start, unsigned int middle, unsigned int end, int valToInsert);
		unsigned int	binarySearchVector(std::vector<int>& _vector, unsigned int low, unsigned int high, int valToInsert);

		void			jacobsthalInsert(int jacobsthalNumber, unsigned int& appendageCount, std::vector<int>& mainChain, std::vector< std::pair<int,int> >& pairElements);
		void			binaryInsert(std::vector<int>& mainChain, std::vector< std::pair<int,int> >& pairElements);

		void			recurseVector(int pairSize);
};

#endif