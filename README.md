# Student Library Management System

A console-based Library Management System written in modern C++ utilizing Object-Oriented Programming (OOP) paradigms and file I/O for persistent data storage.


## Features

- **Add New Books**: Register books with unique IDs, titles, and author names.
- **Inventory Display**: View all books alongside real-time status (`Available` / `Issued`).
- **Issue & Return Tracking**: Toggle borrowing state with duplicate issuance prevention and validation checks.
- **Data Persistence**: Automatically writes records to `library_data.txt` on state changes and reloads them on startup.


## Tech Stack & Concepts

- **Language**: C++ (C++11 or higher)
- **Paradigm**: Object-Oriented Programming (Encapsulation, Classes & Objects)
- **Data Structures**: `std::vector` (dynamic array container)
- **Persistence**: File streams (`std::ifstream`, `std::ofstream`)
