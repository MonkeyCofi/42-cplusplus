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
# include <set>

class	PMergeMe
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
		PMergeMe();
		~PMergeMe();
		PMergeMe(const PMergeMe& obj);
		PMergeMe&	operator=(const PMergeMe& obj);
		
		void	fillContainers(const char** args);
		int		size();

		long			getJacobsthal(int n);

		void			sortVector();
		void			sortList();

		// utility
		void			printPairs(std::vector< std::pair<int, int> >& print);
		template <typename T>
		int	PMergeMe::binaryInsertSearch(int _toInsert, T& container);
};

#endif