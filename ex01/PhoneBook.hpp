#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define max_contacts 8

# include "Contact.hpp"

class PhoneBook {
  private:
    int     index;
    int     stop_index;
    Contact contact[max_contacts];
  public:
    PhoneBook();
    ~PhoneBook();
    void        add_contact(void);
    void        search_contact(void);
    std::string data_size(std::string val);
};

#endif