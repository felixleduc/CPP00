;/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:27:16 by fleduc            #+#    #+#             */
/*   Updated: 2022/11/11 12:59:08 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
  return ;
}

std::string Contact::get_val(std::string val) {
  if (val == "first")
    return (first_name);
  if (val == "last")
    return (last_name);
  if (val == "nick")
    return (nickname);
  if (val == "phone")
    return (phone_number);
  if (val == "dark")
    return (darkest_secret);
  return ("");
}

int     Contact::is_set() {
  if (!first_name.empty())
    return (1);
  return (0);
}

void    Contact::set_contact() {
  std::cout << "Enter these informations" << std::endl;
  do {
    std::cout << "first name: ";
    getline(std::cin, first_name);
  } while(first_name == "");
  do {
    std::cout << "last name: ";
    getline(std::cin, last_name);
  } while(last_name == "");
  do {
    std::cout << "nickname: ";
    getline(std::cin, nickname);
  } while(nickname == "");
  do {
    std::cout << "phone number: ";
    getline(std::cin, phone_number);
  } while(phone_number == "");
  do {
    std::cout << "darkest secret: ";
    getline(std::cin, darkest_secret);
  } while(darkest_secret == "");
  std::cout << std::endl;
}

Contact::~Contact() {
  return ;
}
