/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:57 by bhielsch          #+#    #+#             */
/*   Updated: 2023/02/13 16:03:41 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "Contacts.hpp"
#include <cstring>
#include <cstdlib>

class PhoneBook
{
	private :
		Contacts contact[8];

	public :
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		void print_contacts();
		void print_search(int index);
		void my_exit();
		int CountContacts();

};

#endif
