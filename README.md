# 📒 Address Book Project (C Language)

A simple command-line **Address Book** application written in **C**, designed to manage personal contacts efficiently.  
This project demonstrates the use of **structures, file handling, string validation, and modular programming** in C.

---

## 🚀 Features

- Add a new contact  
- Edit existing contacts (by name, phone, or email)  
- Search for a contact  
- Validate name, phone, and email before saving  
- Prevent duplicate entries  
- Save and load contacts from a file  
- User-friendly text-based interface

---

## 🧠 Concepts Used

- **Structures (`struct`)** for contact data  
- **Functions and modular design** for better organization  
- **String handling** (`strcpy`, `strcmp`, `strlen`)  
- **File I/O** (`fopen`, `fprintf`, `fscanf`)  
- **Validation using `<ctype.h>`**  
- **Loops and conditionals** for user interaction

---

## 🧩 Project Structure

AddressBook-NewDesign/
├── main.c
├── contact.c
├── contact.h
├── contact.csv
├── file.c
├── main.c
├── README.md
└── validation.c


## ⚙️ How to Compile and Run

### Using GCC
```bash
gcc *.c


========= Address Book =========
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Save contacts & Exit
Enter your choice: 1
Enter Name : John Doe
Enter Phone No. : 9876543210
Enter Email : john.doe@example.com
Contact Created Successfully!!!


🧰 Requirements

GCC compiler (Linux / macOS / Windows WSL)
Basic understanding of C and command-line usage


👩‍💻 Author

Varshini [varshiniyadav87]
💌 Made with ❤️ in C