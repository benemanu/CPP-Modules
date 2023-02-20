/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:51 by bhielsch          #+#    #+#             */
/*   Updated: 2023/02/13 16:03:32 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include "Contacts.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Welcome to the PhoneBook" << std::endl;
	return;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Goodbye" << std::endl;
	return;
}

void PhoneBook::add()
{
	static int i = 0;
	if (i == 8)
		i-= 8;
	std::string input;
	std::cout << "Enter first name: ";
	while (getline(std::cin, input) && input == "")
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter first name: ";
	}
	contact[i].set_first_name(input);
	std::cout << "Enter last name: ";
	while (getline(std::cin, input) && input == "")
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter last name: ";
	}
	contact[i].set_last_name(input);
	std::cout << "Enter nickname: ";
	while (getline(std::cin, input) && input == "")
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter nickname: ";
	}
	contact[i].set_nickname(input);
	std::cout << "Enter phone number: ";
	while (getline(std::cin, input) && input == "")
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter phone number: ";
	}
	contact[i].set_phonenumber(input);
	std::cout << "Enter darkest secret: ";
	while (getline(std::cin, input) && input == "")
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "Enter darkest secret: ";
	}
	contact[i].set_darkest_secret(input);
	i++;
}

void    PhoneBook::search()
{
	bool flag = false;
	int num = 0;
	if (contact[0].get_first_name() == "")
		std::cout << "No contacts to search" << std::endl;
	else
	{
		print_contacts();
		while (flag == false)
		{
			std::cout << "Enter index: ";
			std::cin >> num;
			if (num <= 0 || num > 8 || num > CountContacts())
			{
				std::cout << "Invalid input" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				flag = true;
		}
		print_search(num - 1);
		std::cin.clear();
	}
}

void    PhoneBook::print_contacts()
{
	int i = 0;
	int len = 0;
	int len2 = 0;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (contact[++i - 1].get_first_name() != "" && i != 9)
	{
		len2 = 0;
		std::cout << "         " << i << "|";
		len = contact[i - 1].get_first_name().length();
		if (len > 10)
			std::cout << contact[i - 1].get_first_name().substr(0, 9) << "." << "|";
		else
		{
			while (len2 < 10 - len)
			{
				std::cout << " ";
				len2++;
			}
			std::cout << contact[i - 1].get_first_name() << "|";
		}
		len2 = 0;
		len = contact[i - 1].get_last_name().length();
		if (len > 10)
			std::cout << contact[i - 1].get_last_name().substr(0, 9) << "." << "|";
		else
		{
			while (len2 < 10 - len)
			{
				std::cout << " ";
				len2++;
			}
			std::cout << contact[i - 1].get_last_name() << "|";
		}
		len2 = 0;
		len = contact[i - 1].get_nickname().length();
		if (len > 10)
			std::cout << contact[i - 1].get_nickname().substr(0, 9) << ".";
		else
		{
			while (len2 < 10 - len)
			{
				std::cout << " ";
				len2++;
			}
			std::cout << std::right << contact[i - 1].get_nickname();
		}
		std::cout << std::endl;
	}
}

void    PhoneBook::print_search(int index)
{
	std::cout << "First name: " << contact[index].get_first_name() << std::endl;
	std::cout << "Last name: " << contact[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contact[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << contact[index].get_phonenumber() << std::endl;
	std::cout << "Darkest secret: " << contact[index].get_darkest_secret() << std::endl;
}

void    PhoneBook::my_exit()
{
	exit(0);
}

int PhoneBook::CountContacts()
{
	int i = 0;
	while (i < 8 && contact[i].get_first_name() != "")
		i++;
	return (i);
}
