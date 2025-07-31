/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:20:44 by dario             #+#    #+#             */
/*   Updated: 2025/07/31 05:28:09 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

class Contact {


	public:
	Contact();
	Contact(std::string fN, std::string lN, std::string nN,
			std::string dS, int pN);
	~Contact();

	std::string		GetFirstName();
	std::string		GetLastName();
	std::string		GetNickName();
	std::string		GetDarkestSecret();
	int				GetPhoneNumber();
	

	private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_secret;
	int			_phoneNumber;
};

#endif