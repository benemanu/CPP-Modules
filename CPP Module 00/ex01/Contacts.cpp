/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:02:01 by bhielsch          #+#    #+#             */
/*   Updated: 2023/02/13 16:03:10 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contacts::Contacts()
{
	return;
}

Contacts::~Contacts()
{
	return;
}

void Contacts::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void Contacts::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void Contacts::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contacts::set_phonenumber(std::string phonenumber)
{
	this->phonenumber = phonenumber;
}

void Contacts::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

std::string Contacts::get_first_name()
{
	return this->first_name;
}

std::string Contacts::get_last_name()
{
	return this->last_name;
}

std::string Contacts::get_nickname()
{
	return this->nickname;
}

std::string Contacts::get_phonenumber()
{
	return this->phonenumber;
}

std::string Contacts::get_darkest_secret()
{
	return this->darkest_secret;
}
