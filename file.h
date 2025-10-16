#ifndef FILE_H
#define FILE_H

#include "contact.h"

// function prototypes to load from file and to save to file
void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif
