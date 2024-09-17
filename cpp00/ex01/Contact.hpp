/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:28:03 by pipolint          #+#    #+#             */
/*   Updated: 2024/08/31 14:21:16 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		void		print_query(std::string str);
		bool		m_empty;
		std::string m_firstName;
		std::string m_lastName;
		std::string m_phoneNumber;
		std::string	m_nickName;
		std::string	m_darkestSecret;
	public:
		// all the setters and getters
		void		setContact();
		void		setNames();
		void		setNumber();
		void		setSecret();
		void		setNonEmpty();
		bool		isEmpty();
		std::string	getFirst() const;
		std::string	getLast() const;
		std::string	getNumber() const;
		std::string	getSecret() const;
		std::string getNick() const;
		Contact();
};

#endif