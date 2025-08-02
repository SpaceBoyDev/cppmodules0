/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:17:54 by dario             #+#    #+#             */
/*   Updated: 2025/08/02 22:35:15 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iomanip>

PhoneBook::PhoneBook(int cI, bool lF)
	: contactNbr(cI), contactListFull(lF) {}

PhoneBook::~PhoneBook() {}

Contact *PhoneBook::GetContactList()
{
	return _contactList;
}

std::string PhoneBook::TruncateString(std::string str, size_t maxLen)
{
	if (str.length() > maxLen)
		return (str.substr(0, maxLen - 1) + ".");
	return str;
}

void PhoneBook::AddContact(Contact &contact)
{
	if (contactNbr < 8)
		GetContactList()[contactNbr++] = contact;
	else
	{
		contactListFull = true;
		contactNbr = 0;
		GetContactList()[contactNbr++] = contact;
	}
}

void PhoneBook::SearchContact(int nbr)
{
	if ((!contactListFull && nbr >= contactNbr) || nbr < 0)
	{
		std::cout << "Invalid index :(" << std::endl;
		return;
	}
	std::cout << "First Name => " << GetContactList()[nbr].GetFirstName() << std::endl;
	std::cout << "Last Name => " << GetContactList()[nbr].GetLastName() << std::endl;
	std::cout << "NickName => " << GetContactList()[nbr].GetNickName() << std::endl;
	std::cout << "Phone Number => " << GetContactList()[nbr].GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret => " << GetContactList()[nbr].GetDarkestSecret() << std::endl;
}

void PhoneBook::DisplayContacts(int max)
{
	std::cout << "╔══════════════════════════════════════════╗"
		<< std::endl;
	std::cout << std::setw(10) << "Index" << "║"
		<< std::setw(10) << "First Name" << "║"
		<< std::setw(10) << "Last Name" << "║"
		<< std::setw(10) << "Nickname"
		<< std::endl;
	for (int i = 0; i < max; i++)
	{
		if (!contactListFull && i >= contactNbr)
			break;
		std::cout << std::setw(10) << i << "║"
		<< std::setw(10) << TruncateString(GetContactList()[i].GetFirstName(), 10) << "║"
		<< std::setw(10) << TruncateString(GetContactList()[i].GetLastName(), 10) << "║"
		<< std::setw(10) << TruncateString(GetContactList()[i].GetNickName(), 10) << "║"
		<< std::endl;
	}
	std::cout << "╚══════════════════════════════════════════╝"
		<< std::endl;
}

void PhoneBook::DisplayContactInfo(Contact &contact)
{
	std::cout << "First Name : " << contact.GetFirstName() << std::endl;
	std::cout << "Last Name : " << contact.GetLastName() << std::endl;
	std::cout << "NickName : " << contact.GetNickName() << std::endl;
	std::cout << "Phone Number : " << contact.GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << contact.GetDarkestSecret() << std::endl;
}
