#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define max_contacts 8

# include "Contact.hpp"

class PhoneBook {
  private:
    int     index;
    Contact contact[max_contacts];
  public:
    PhoneBook();
    void    add_contact();
    void    search_contact();
};

#endif