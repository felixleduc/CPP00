/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:29:14 by fleduc            #+#    #+#             */
/*   Updated: 2022/11/11 13:14:39 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

static void    helper(void) {
    std::cout << "Enter one of these 3 commands:\n" << std::endl;
    std::cout << "ADD :     add a new contact to your phonebook" << std::endl;
    std::cout << "SEARCH :  display your phonebook" << std::endl;
    std::cout << "EXIT :    quit\n" << std::endl;
}

int main(void) {
  PhoneBook     phonebook;
  std::string   command;

  helper();
  while (std::getline(std::cin, command))
  {
    if (command == "ADD")
      phonebook.add_contact();
    else if (command == "SEARCH")
      phonebook.search_contact();
    else if (command == "EXIT")
      break;
  }
  return 0;
}
