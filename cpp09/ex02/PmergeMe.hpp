/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:44:26 by pipolint          #+#    #+#             */
/*   Updated: 2025/06/15 18:51:45 by ppolinta         ###   ########.fr       */
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
# include <ctime>
# include <sys/time.h>

class	PmergeMe
{
	private:
		static unsigned int		comparsionCount;
		std::vector<int>		vector;
		std::list<int>			list;
		std::set<int>			set;
		static long				sequence[];
		long long				vector_ms;
		long long				list_ms;

		unsigned int	comp(int val1, int val2);
		void			sortVector();
		void			sortList();
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& obj);
		PmergeMe&	operator=(const PmergeMe& obj);
		
		void	fillContainers(char** args);
		int		size();
		
		long	getJacobsthal(int n);
		long long	getVectorTime() const;
		long long	getListTime() const;
		
		// vector utility
		int		binaryInsertSearch(int _toInsert, size_t capIndex, std::vector<int>& searchVector);
		void	insertPend(std::vector<int>& pendChain);
		void	positionPendElements(std::vector<int>& unsorted_winners, std::vector<int>& sorted_winners, 
			std::vector<int>& losers, std::vector<int>& pendChain);
		void	printVector(std::vector<int>& print);
		void	printInternalVector();
		void	mergeInsertionVector();
			
			// list utility
		std::list<int>::iterator	advancedIterator(std::list<int>::iterator iterator, int advanceBy);
		void	printInternalList();
		void	printList(std::list<int>& print);
		int		binaryInsertSearch(int _toInsert, size_t capIndex, std::list<int>& searchList);
		void	positionPendElements(std::list<int>& unsorted_winners, std::list<int>& sorted_winners, 
			std::list<int>& losers, std::list<int>& pendChain);
		void	insertPend(std::list<int>& pendChain);
		void	mergeInsertionList();
};

#endif