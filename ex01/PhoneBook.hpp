/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:18:17 by dario             #+#    #+#             */
/*   Updated: 2025/07/31 06:31:23 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iostream>
#include "Contact.hpp"

class PhoneBook {

	public:

	PhoneBook();
	~PhoneBook();

	int			contactNbr = 0;
	bool		contactListFull = false;
	Contact		*GetContactList();
	std::string	TruncateString(std::string str, int maxLen);
	void		AddContact(Contact &contact);
	void		SearchContact(int nbr);
	void		DisplayContacts(int max);
	void		DisplayContactInfo(Contact &contact);

	private:
	Contact	_contactList[8];
};

#endif