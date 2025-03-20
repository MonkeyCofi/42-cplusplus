/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:44:26 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/20 19:51:28 by ppolinta         ###   ########.fr       */
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
		
		void	sortVector();
		void	sortList();
		void	printVector();
		
		void	recurseVector(int pairSize);
};

#endif