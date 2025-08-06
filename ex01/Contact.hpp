/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:20:44 by dario             #+#    #+#             */
/*   Updated: 2025/08/06 02:13:53 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <string>

class Contact {

	public:
	Contact();
	Contact(std::string fN, std::string lN, std::string nN,
			int pN, std::string dS);
	~Contact();

	std::string		GetFirstName(void);
	std::string		GetLastName(void);
	std::string		GetNickName(void);
	int				GetPhoneNumber(void);
	std::string		GetDarkestSecret(void);

	private:
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickName;
	int				_phoneNumber;
	std::string		_secret;
};

#endif