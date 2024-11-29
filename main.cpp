#include "Library.h"
#include <iostream>
#include <memory>

int main() {
  Library library;

  // Add some books
  // Choose one of the following based on memory management method
  // Raw Pointer Version
  // library.addBook(new Book(1, "The Great Gatsby", "F. Scott Fitzgerald"));
  // library.addBook(new Book(2, "1984", "George Orwell"));
  // library.addBook(new Book(3, "To Kill a Mockingbird", "Harper Lee"));

  // Smart Pointer Version
  library.addBook(
      std::make_shared<Book>(1, "The Great Gatsby", "F. Scott Fitzgerald"));
  library.addBook(std::make_shared<Book>(2, "1984", "George Orwell"));
  library.addBook(
      std::make_shared<Book>(3, "To Kill a Mockingbird", "Harper Lee"));

  // Add some users
  // Raw Pointer Version
  // library.addUser(new User(1, "Alice"));
  // library.addUser(new User(2, "Bob"));

  // Smart Pointer Version
  library.addUser(std::make_shared<User>(1, "Alice"));
  library.addUser(std::make_shared<User>(2, "Bob"));

  // Simple interactive menu
  int choice;
  while (true) {
    std::cout << "\nLibrary Management System\n";
    std::cout << "1. List Books\n";
    std::cout << "2. List Users\n";
    std::cout << "3. Borrow Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice == 1) {
      library.listBooks();
    } else if (choice == 2) {
      library.listUsers();
    } else if (choice == 3) {
      int userId, bookId;
      std::cout << "Enter User ID: ";
      std::cin >> userId;
      std::cout << "Enter Book ID: ";
      std::cin >> bookId;
      if (library.borrowBook(userId, bookId)) {
        std::cout << "Book borrowed successfully.\n";
      } else {
        std::cout << "Failed to borrow book.\n";
      }
    } else if (choice == 4) {
      int userId, bookId;
      std::cout << "Enter User ID: ";
      std::cin >> userId;
      std::cout << "Enter Book ID: ";
      std::cin >> bookId;
      if (library.returnBook(userId, bookId)) {
        std::cout << "Book returned successfully.\n";
      } else {
        std::cout << "Failed to return book.\n";
      }
    } else if (choice == 5) {
      break;
    } else {
      std::cout << "Invalid choice. Please try again.\n";
    }
  }

  return 0;
}
