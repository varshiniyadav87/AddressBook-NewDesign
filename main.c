/* 
    Name          : NAKKA VARSHINI
    Date          : 16-10-2025
    Project       : Address Book Application in C
    Description   : Console-based address book to create, search, edit, delete, list, and save contacts.
                    Each contact includes name, phone number, and email.
                    Supports sorting contacts by name, phone, or email.
    Sample Input/Output:
                    Enter your choice: 1
                    Enter Name : John Doe
                    Enter Phone No. : 9876543210
                    Enter Email : john.doe@example.com
                    Contact Created Successfully!!!
*/

#include <stdio.h>
#include <stdlib.h>
#include "contact.h"

int main() {
    int choice,sortChoice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    // Loop until user enters 7
    do {
        // Display menu 
        printf("\n========= Address Book =========\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts & Exit\n");		
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:     //create contact
                createContact(&addressBook);    
                break;
            case 2:     //search contact
                searchContact(&addressBook);    
                break;
            case 3:     //edit contact
                editContact(&addressBook);      
                break;
            case 4:     //delete contact
                deleteContact(&addressBook);    
                break;
            case 5:     //list all the contacts through sorting
                printf("\nSorting Choice:\n1. Sort By Name\n2. Sort By contact\n3. Sort By Email\nEnter Sorting Choice : ");
                scanf("%d",&sortChoice);
                listContacts(&addressBook, sortChoice);     
                break;
            case 6:     //save contacts 
                saveAndExit(&addressBook);       
                break;
            default:    //invalid input
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}
