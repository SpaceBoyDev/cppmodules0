/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:21:06 by dario             #+#    #+#             */
/*   Updated: 2025/08/02 22:34:04 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string fN, std::string lN, std::string nN, int pN, std::string s)
	: _firstName(fN), _lastName(lN), _nickName(nN), _phoneNumber(pN), _secret(s)
{}

Contact::~Contact() {}

std::string		Contact::GetFirstName()
{
	return this->_firstName;
}

std::string Contact::GetLastName()
{
	return this->_lastName;
}

std::string Contact::GetNickName()
{
	return this->_nickName;
}

int Contact::GetPhoneNumber()
{
	return this->_phoneNumber;
}

std::string Contact::GetDarkestSecret()
{
	return this->_secret;
}
