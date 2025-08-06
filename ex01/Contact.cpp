/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:21:06 by dario             #+#    #+#             */
/*   Updated: 2025/08/06 02:14:07 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string fN, std::string lN, std::string nN, int pN, std::string s)
	: _firstName(fN), _lastName(lN), _nickName(nN), _phoneNumber(pN), _secret(s)
{}

Contact::~Contact() {}

std::string		Contact::GetFirstName(void)
{
	return this->_firstName;
}

std::string Contact::GetLastName(void)
{
	return this->_lastName;
}

std::string Contact::GetNickName(void)
{
	return this->_nickName;
}

int Contact::GetPhoneNumber(void)
{
	return this->_phoneNumber;
}

std::string Contact::GetDarkestSecret(void)
{
	return this->_secret;
}
