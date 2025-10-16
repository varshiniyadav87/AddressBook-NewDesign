#include <stdio.h>
#include "file.h"

// function to save current details to csv file
void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp = fopen("contacts.csv","w");

    // Write total count of contacts to file first
    fprintf(fp,"%d\n",addressBook->contactCount);

    // Write each contact's data in CSV format
    for (int i = 0 ; i < addressBook->contactCount ; i++)
        fprintf(fp,"%s,%s,%s\n", addressBook->contacts[i].name , addressBook->contacts[i].phone , addressBook->contacts[i].email) ;
    fclose(fp);
}


// Load contacts from the CSV file into address book at program start
void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp;
    fp = fopen("contacts.csv","r");
    if (fp == NULL) {
        printf("File not found ");
        return;
    }

    // Read number of contacts
    fscanf(fp,"%d\n",&addressBook->contactCount);

    // Read each contacts data from csv and store in addressbook
    for (int i = 0 ; i < addressBook->contactCount ; i++)
        fscanf(fp,"%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name , addressBook->contacts[i].phone ,addressBook->contacts[i].email) ;
    
    fclose(fp);
}
