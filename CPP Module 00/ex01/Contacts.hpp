/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:38 by bhielsch          #+#    #+#             */
/*   Updated: 2023/02/13 16:03:17 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

class Contacts
{
	private :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string darkest_secret;

	public :
		Contacts();
		~Contacts();
		void set_first_name(std::string first_name);
		void set_last_name(std::string last_name);
		void set_nickname(std::string nickname);
		void set_phonenumber(std::string phonenumber);
		void set_darkest_secret(std::string darkest_secret);
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phonenumber();
		std::string get_darkest_secret();

};

#endif
