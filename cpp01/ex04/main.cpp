/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:28:14 by pipolint          #+#    #+#             */
/*   Updated: 2024/08/31 18:29:20 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		return (1);
	}
	std::ifstream infile;
	infile.open(av[1]);
	if (!infile.is_open())
	{
		std::cerr << "Couldn't open " << std::string(av[1]) << std::endl;
		return (1);
	}
	std::string line;
	std::ofstream replace_file;
	replace_file.open(std::string(av[1]).append(".replace"));
	if (!replace_file.is_open())
	{
		std::cerr << "Couldn't open outfile" << std::endl;
		return (1);
	}
	while (getline(infile, line))
	{
		size_t found_pos = 0;
		found_pos = line.find(std::string(av[2]));
		for (int i = 0; line[i]; i++)
		{
			found_pos = line.substr(i, std::string::npos).find(std::string(av[2]));
			if (found_pos != std::string::npos)
			{
				line.erase(found_pos, std::string(av[2]).length());
				line.insert(found_pos, std::string(av[3]));
				i += found_pos;
			}
		}
		replace_file << line;
		replace_file << std::endl;
	}
	replace_file.close();
	infile.close();
}