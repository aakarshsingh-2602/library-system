#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Book Class
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }
};


class Library {
private:
    vector<Book> books;
    const string filename = "library_data.txt";

  
    void saveToFile() {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "[ERROR] Could not open file to save data.\n";
            return;
        }
        
        for (const auto& book : books) {
          
            outFile << book.id << "\n"
                    << book.isIssued << "\n"
                    << book.title << "\n"
                    << book.author << "\n";
        }
        outFile.close();
    }

  
    void loadFromFile() {
        ifstream inFile(filename);
        if (!inFile) {
           
            return; 
        }

        int id;
        bool isIssued;
        string title, author;

       
        while (inFile >> id >> isIssued) {
            inFile.ignore(); 
            getline(inFile, title);
            getline(inFile, author);

         
            Book loadedBook(id, title, author);
            loadedBook.isIssued = isIssued; 
            books.push_back(loadedBook);
        }
        inFile.close();
    }

public:
   
    Library() {
        loadFromFile();
    }

    void addBook(int id, string title, string author) {
        Book newBook(id, title, author);
        books.push_back(newBook);
        saveToFile();
        cout << "\n[SUCCESS] Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "\n[INFO] The library is currently empty.\n";
            return;
        }
        cout << "\n--- Library Inventory ---\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id 
                 << " | Title: " << book.title 
                 << " | Author: " << book.author 
                 << " | Status: " << (book.isIssued ? "Issued" : "Available") << "\n";
        }
    }

    void issueBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    book.isIssued = true;
                    saveToFile();
                    cout << "\n[SUCCESS] Book issued successfully.\n";
                } else {
                    cout << "\n[WARNING] Book is already issued.\n";
                }
                return;
            }
        }
        cout << "\n[ERROR] Book ID not found.\n";
    }

    void returnBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    book.isIssued = false;
                    saveToFile(); 
                    cout << "\n[SUCCESS] Book returned successfully.\n";
                } else {
                    cout << "\n[WARNING] This book was not issued.\n";
                }
                return;
            }
        }
        cout << "\n[ERROR] Book ID not found.\n";
    }
};

int main() {
    Library myLibrary;
    int choice, id;
    string title, author;

    while (true) {
        cout << "\n=====================================";
        cout << "\n STUDENT LIBRARY MANAGEMENT SYSTEM";
        cout << "\n=====================================\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Issue a Book\n";
        cout << "4. Return a Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore(); 
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Author Name: ";
                getline(cin, author);
                myLibrary.addBook(id, title, author);
                break;
            case 2:
                myLibrary.displayBooks();
                break;
            case 3:
                cout << "Enter Book ID to Issue: ";
                cin >> id;
                myLibrary.issueBook(id);
                break;
            case 4:
                cout << "Enter Book ID to Return: ";
                cin >> id;
                myLibrary.returnBook(id);
                break;
            case 5:
                cout << "Exiting system. Goodbye!\n";
                return 0;
            default:
                cout << "\n[ERROR] Invalid choice. Please try again.\n";
        }
    }
}
