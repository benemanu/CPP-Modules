/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:44 by bhielsch          #+#    #+#             */
/*   Updated: 2023/02/13 16:03:23 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contacts.hpp"
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
	(void) argv; 
	PhoneBook book;
	if (argc > 2)
		std::cout << "Too many arguments" << std::endl;
	else
	{
		while (1)
		{
			std::cin.clear();
			std::string input;
			std::cout << "Enter command: ";
			std::getline(std::cin, input);
			if (input == "EXIT")
				exit (0);
			else if (input == "ADD")
				book.add();
			else if (input == "SEARCH")
			{
				book.search();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
				
			else
				std::cout << "Invalid command" << std::endl;
		}
	}
	return (0);
}
