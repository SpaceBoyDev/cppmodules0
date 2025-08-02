/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:43:48 by dario             #+#    #+#             */
/*   Updated: 2025/08/02 22:35:05 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

#include "Contact.hpp"
#include "PhoneBook.hpp"

# define RST		"\033[0m"
# define RED		"\033[1;31m"
# define BLUE		"\033[1;34m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"

# define BG_RST		"\033[0m"
# define BG_RED		"\033[41m"
# define BG_GREEN	"\033[42m"
# define BG_YELLOW	"\033[43m"
# define BG_BLUE	"\033[44m"
# define BG_MAGENTA	"\033[45m"
# define BG_CYAN	"\033[46m"
# define BG_WHITE	"\033[47m"

void	cmd_add(PhoneBook &phoneBook)
{
	std::string	firstName, lastName, nickName, secret;
	int			phoneNumber;
	std::cout << BG_CYAN "Introduce their first name:" BG_RST << std::endl;
	std::cin >> firstName;
	std::cout << BG_CYAN "Introduce their last name:" BG_RST << std::endl;
	std::cin >> lastName;
	std::cout << BG_CYAN "Introduce their nickname:" BG_RST << std::endl;
	std::cin >> nickName;
	std::cout << BG_CYAN "Introduce their phone number:" BG_RST << std::endl;
	std::cin >> phoneNumber;
	while (std::cin.fail() || phoneNumber < 0)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << BG_RED "This is not a phone number!" BG_RST << std::endl;
		std::cout << BG_CYAN "Introduce their phone number:" BG_RST << std::endl;
		std::cin >> phoneNumber;
	}
	std::cout << BG_CYAN "Introduce their darkest secret:" BG_RST << std::endl;
	std::cin >> secret;
	Contact	contact(firstName, lastName, nickName, phoneNumber, secret);
	phoneBook.AddContact(contact);
	std::cout << BG_GREEN "Added" GREEN " " << firstName
		<< RST BG_GREEN " to the contact list!" BG_RST << std::endl;
}

void	cmd_search(PhoneBook &phoneBook)
{
	int	index;
	phoneBook.DisplayContacts(8);
	std::cout << BG_CYAN "Introduce the index number:" BG_RST << std::endl;
	std::cin >> index;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << BG_RED "This is not a number!" BG_RST << std::endl;
		std::cout << BG_CYAN "Introduce the index number:" BG_RST << std::endl;
		std::cin >> index;
	}
	phoneBook.SearchContact(index);
}

int	main(void)
{
	PhoneBook	phoneBook(0, false);
	std::string	cmd;

	while (true)
	{
		std::cout << BG_BLUE "What do you want to do?" BG_RST << std::endl
			<< BLUE "(ADD, SEARCH, EXIT)" RST << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			cmd_add(phoneBook);
		else if (cmd == "SEARCH")
			cmd_search(phoneBook);
		else if (cmd == "EXIT")
			return (0);
	}
	return (0);
}