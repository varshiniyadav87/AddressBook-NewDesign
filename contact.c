#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"


// list all contacts 
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on sort criteria
    int compareRes = 0 ;
    for(int i = 0 ; i < addressBook -> contactCount - 1 ; i++){
        for(int j = 0 ; j < addressBook -> contactCount - i - 1 ; j++){

            // Compare adjacent contacts according to the criteria
            if (sortCriteria == 1)
                compareRes = strcasecmp(addressBook -> contacts[j].name , addressBook -> contacts[j + 1].name);
            else if(sortCriteria == 2)
                compareRes = strcasecmp(addressBook -> contacts[j].phone , addressBook -> contacts[j + 1].phone);
            else if(sortCriteria == 3)
                compareRes = strcasecmp(addressBook -> contacts[j].email , addressBook -> contacts[j + 1].email);
            
            // Swap contacts if condition is true
            if(compareRes > 0){
                Contact duplicate = addressBook -> contacts[j] ;
                addressBook -> contacts[j] = addressBook -> contacts[j + 1] ;
                addressBook -> contacts[j + 1] = duplicate ; 
            }
        }
    }

    // Print sorted contacts
    for(int i = 0 ; i < addressBook -> contactCount ; i++){
        printf("%-18s%-18s%-8s\n",  addressBook -> contacts[i].name ,
                                addressBook -> contacts[i].phone,
                                addressBook -> contacts[i].email);
    }
}

// Load contacts from file during initialization (After files)
void initialize(AddressBook *addressBook) {  
    loadContactsFromFile(addressBook);
}

// save contacts & to exit the program
void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    printf("Contacts have been saved.Exiting the program!!!\n");
    exit(EXIT_SUCCESS); // Exit the program
}

// create a new contact through validation
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char newContactName[50]; 
    char newContactPhone[20];
    char newContactEmail[50];

    // Get and validate name , phone number , email
    getName(newContactName);
    getPhoneNumber(addressBook,newContactPhone);
    getEmail(addressBook,newContactEmail);

    // If validation is successful then create new contact in addressbook
    strcpy(addressBook->contacts[addressBook->contactCount].name,newContactName);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,newContactPhone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,newContactEmail);
    printf("Contact Created Successfully!!!\n");
    addressBook->contactCount++;

}

// Search contact based on user choice and print results
int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int searchBy;
    printf("\nSearching Choice:\n1. Search By Name\n2. Search By contact\n3. Search By Email\n");
    printf("Enter Searching Choice : ");
    scanf("%d",&searchBy);
    char searchElement[50];
    printf("Enter your search : ");scanf(" %[^\n]",searchElement);

    int compareRes = 0 ;
    int found = 0 ; 

    // Iterate contacts to find the matching
    for (int i = 0 ; i < addressBook -> contactCount ; i++){
        if (searchBy == 1){
            compareRes = strcasecmp(addressBook->contacts[i].name , searchElement);
        }
        else if (searchBy == 2){
            compareRes = strcasecmp(addressBook->contacts[i].phone , searchElement);
        }
        else if (searchBy == 3){
            compareRes = strcasecmp(addressBook->contacts[i].email , searchElement);
        }

        // If match found print the result
        if(!compareRes){
            found = 1;
            printf("%-10d%-18s%-18s%-8s\n", i , addressBook -> contacts[i].name ,
                                addressBook -> contacts[i].phone,
                                addressBook -> contacts[i].email);
        }
    }

    if (!found) {
        printf("Contact Not Found\n");
        return 0;
    }
    else return 1;
}

// Edit existing contact details after searching in address book
void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    int found = searchContact(addressBook);              // Search for contact to edit

    if (found) {                                         // If contact found
        int editChoice, index;
        printf("Enter Index : "); scanf("%d", &index);   // Ask user for contact index
        printf("Editing Choice:\n1. Edit By Name\n2. Edit By Contact\n3. Edit By Email\n");
        printf("Enter your Choice : "); scanf("%d", &editChoice);  // Get edit option

        char newContact[50];                             // Temporary buffer for new data

        if (editChoice == 1) {                           // Edit name
            getName(newContact);                         // Get new name
            strcpy(addressBook->contacts[index].name, newContact);  // Update name
            printf("Name edited successfully!!!\n");
        }
        else if (editChoice == 2) {                      // Edit phone number
            getPhoneNumber(addressBook, newContact);      // Get new phone number
            strcpy(addressBook->contacts[index].phone, newContact); // Update phone
            printf("Phone No. edited successfully!!!\n");
        }
        else if (editChoice == 3) {                      // Edit email
            getEmail(addressBook, newContact);            // Get new email
            strcpy(addressBook->contacts[index].email, newContact); // Update email
            printf("Email edited successfully!!!\n");
        }
    }
}

// Delete a contact after searching 
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int found = searchContact(addressBook) ; 

    // If contact found  delete that contact 
    if(found){
        int index;
        printf("Enter Index : ");scanf("%d",&index);

        // Shift contacts to left by one from the found index 
        for (int i = index ; i < addressBook -> contactCount ; i++){
            addressBook->contacts[i] =  addressBook->contacts[i + 1];
        }
        printf("Contact deleted successfully!!!\n");
        addressBook -> contactCount-- ;
    }   
    
    
}



