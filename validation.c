#include "contact.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

// Validate that the name contains only alphabets and spaces
int validateName(char *name){
    int i = 0 ;
    // Traverse each character and check if alphabet or space
    while(name[i]){
        if( !isalpha(name[i]) && name[i] != ' ')
            return 0 ;      //invalid character found
        i++;
    }
    return 1;       //valid name
}

// Get a valid name from the user
void getName(char *name){
    int checkResult;
    do{
        printf("Enter Name : ");                // Prompt for name
        scanf(" %49[^\n]",name);                // Read input safely 
        checkResult = validateName(name);       // Validate name
        if (!checkResult)                       // Show error if invalid
            printf("Name is Invalid!!!\n");
    }while(!checkResult);                       // Repeat until valid
}

// Validate phone number for length, digits only, and uniqueness
int validatePhone(AddressBook *addressBook , char *phone){
    int len = strlen(phone);

    // Check length is exactly 10
    if (len != 10)
        return 0;

    // Check all characters are digits
    for(int i = 0 ; i < len ; i++){
        if(!isdigit(phone[i]))
            return 0;
    }

    // Check phone number uniqueness within address book
    for (int i = 0 ; i < addressBook -> contactCount ; i++){
        if (!strcmp(addressBook -> contacts[i].phone,phone))
            return 0 ;
    }

    return 1;   //valid phone number
}

// Get a valid phone number from the user
void getPhoneNumber(AddressBook *addressBook ,char *number){
    int checkResult;
    do{
        printf("Enter Phone No. : ");                       // Prompt for phone number
        scanf(" %49[^\n]",number);                          // Read input safely
        checkResult = validatePhone(addressBook,number);    // Validate phone
        if (!checkResult)                                   // Show error if invalid
            printf("Phone No. is Invalid!!!\n");            
    }while(!checkResult);                                   // Repeat until valid
}

// Validate email format and uniqueness in address book
int validateEmail(AddressBook *addressBook , char *email){

    // Check whether email is valid or not
    for (int i = 0 ; i < addressBook -> contactCount ; i++){
        if (!strcmp(addressBook -> contacts[i].email,email))
            return 0 ;  //duplicate email found
    }

    //check presence of '@' 
    char *findAtTheRate = strstr(email,"@");  
    
    // if '@' not found return 0
    if(!findAtTheRate)
        return 0;         

    //check presence of '.' after '@' 
    char *findDot = strstr(findAtTheRate,"."); 
    
    // if '.' not found return 0
    if(!findDot) 
        return 0;         

    // validate username part of email 
    while(*email != *findAtTheRate){
        // Return 0 if consecutive dots are present or if non valid
        if ((*email == '.' && *(email+1) == '.') || (!islower(*email) && !isdigit(*email) && *email != '.'))
            return 0;
        email++;
    }

    //move pointer after '@' 
    email = findAtTheRate + 1;      
    
    //validate domain has alphabets or not 
    while(*email != *findDot){
        if(!islower(*email)) 
            return 0;   //domain part contains invalid character
        email++;
    }
    
    //move pointer after '.' 
    email = findDot + 1;        

    // validate last part of email has alphabets or not
    while(*email){
        if(!islower(*email)) 
            return 0;   //contains invalid character   
        email++; 
    }

    return 1;   //valid email
}

// Get a valid email address from the user
void getEmail(AddressBook *addressBook ,char *email){
    int checkResult;
    do{
        printf("Enter Email : ");                           // Prompt for email
        scanf(" %49[^\n]",email);                           // Read input safely
        checkResult = validateEmail(addressBook,email);     // Validate email
        if (!checkResult)                                   // Show error if invalid
            printf("Email is Invalid!!!\n");
    }while(!checkResult);                                   // Repeat until valid
}
