#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

// structure representation of contact
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

// structure representation of multiple contacts
typedef struct {
    Contact contacts[100];  //array to hold contacts
    int contactCount;       //number of contacts stored
    
} AddressBook;

// Function prototypes for performing operation on contacts
void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveAndExit(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);

// Get and Validate function prototypes to verify inputs
void getName(char *name);
void getPhoneNumber(AddressBook *addressBook ,char *number);
void getEmail(AddressBook *addressBook ,char *email);
int validateName(char *name);
int validatePhone(AddressBook *addressBook , char *phone);
int validateEmail(AddressBook *addressBook , char *email);
#endif
