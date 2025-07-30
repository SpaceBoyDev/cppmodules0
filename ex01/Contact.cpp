/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:21:06 by dario             #+#    #+#             */
/*   Updated: 2025/07/30 23:43:44 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string fN, std::string lN, std::string nN, std::string s,
	int pN) : _firstName(fN), _lastName(lN), _nickName(nN), _secret(s), _phoneNumber (pN) 
{}

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

std::string Contact::GetDarkestSecret()
{
	return this->_secret;
}

int Contact::GetPhoneNumber()
{
	return this->_phoneNumber;
}
