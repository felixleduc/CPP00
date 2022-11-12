/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:27:25 by fleduc            #+#    #+#             */
/*   Updated: 2022/11/11 23:27:03 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
  stop_index = 0;
  index = 0;
  return ;
}

void    PhoneBook::add_contact() {
  if (index == 8)
    index = 0;
  contact[index].set_contact();
  ++index;
  if (stop_index < 7)
    ++stop_index;
}

std::string PhoneBook::data_size(std::string val) {
  if (val.length() > 10) {
    val.resize(9);
    val.append(".");
  }
  return (val);
}

void    PhoneBook::search_contact() {
  int         i = -1;
  int         err = 0;
  int         x;
  std::string cmd;

  std::cout << std::setw(10) << "Index" << "|"
            << std::setw(10) << "First name" << "|"
            << std::setw(10) << "Last name" << "|"
            << std::setw(10) << "Nickname" << std::endl;
  while (contact[++i].is_set())
  {
    std::cout << std::setw(10) << i << "|"
              << std::setw(10) << data_size(contact[i].get_val("first")) << "|"
              << std::setw(10) << data_size(contact[i].get_val("last")) << "|"
              << std::setw(10) << data_size(contact[i].get_val("nick")) << std::endl;
  }
  std::cout << std::endl << "Enter a contact index: ";
  std::getline(std::cin, cmd);
  try {
    x = std::stoi(cmd);
  }
  catch (std::invalid_argument) {
    std::cout << "That's not a number :(\n" << std::endl;
    ++err;
  }
  if (!err) {
    if (x < 0 || x > stop_index - 1)
      std::cout << "Not a valid index :(\n" << std::endl;
    else
    {
      std::cout << std::endl << "|---------- Contact at index " << x << " ----------|" << std::endl
                << "First name:     " << contact[x].get_val("first") << std::endl
                << "Last name:      " << contact[x].get_val("last") << std::endl
                << "Nickname:       " << contact[x].get_val("nick") << std::endl
                << "Phone number:   " << contact[x].get_val("phone") << std::endl
                << "Darkest secret: " << contact[x].get_val("dark") << std::endl << std::endl;
    }
  }
}

PhoneBook::~PhoneBook() {
  return ;
}