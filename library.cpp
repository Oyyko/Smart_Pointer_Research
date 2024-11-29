#include "Library.h"
#include <iostream>

// Raw Pointer Version Constructor
// Library::Library() {}

// Smart Pointer Version Constructor
Library::Library() {}

// Raw Pointer Version Destructor
// Library::~Library() {
//     for(auto book : books) {
//         delete book;
//     }
//     for(auto user : users) {
//         delete user;
//     }
// }

// Smart Pointer Version Destructor
Library::~Library() {
  // Smart pointers automatically manage memory
}

// Raw Pointer Version
// void Library::addBook(Book* book) {
//     books.push_back(book);
// }

// void Library::addUser(User* user) {
//     users.push_back(user);
// }

// Smart Pointer Version
void Library::addBook(std::shared_ptr<Book> book) { books.push_back(book); }

void Library::addUser(std::shared_ptr<User> user) { users.push_back(user); }

// Raw Pointer Version
// Book* Library::findBookById(int id) const {
//     for(auto book : books) {
//         if(book->getId() == id) {
//             return book;
//         }
//     }
//     return nullptr;
// }

// User* Library::findUserById(int id) const {
//     for(auto user : users) {
//         if(user->getId() == id) {
//             return user;
//         }
//     }
//     return nullptr;
// }

// Smart Pointer Version
std::shared_ptr<Book> Library::findBookById(int id) const {
  for (const auto &book : books) {
    if (book->getId() == id) {
      return book;
    }
  }
  return nullptr;
}

std::shared_ptr<User> Library::findUserById(int id) const {
  for (const auto &user : users) {
    if (user->getId() == id) {
      return user;
    }
  }
  return nullptr;
}

// Raw Pointer Version
// bool Library::borrowBook(int userId, int bookId) {
//     User* user = findUserById(userId);
//     Book* book = findBookById(bookId);
//     if(user && book && book->getBorrowedBy() == nullptr) {
//         user->borrowBook(book);
//         return true;
//     }
//     return false;
// }

// bool Library::returnBook(int userId, int bookId) {
//     User* user = findUserById(userId);
//     Book* book = findBookById(bookId);
//     if(user && book && book->getBorrowedBy() == user) {
//         user->returnBook(book);
//         return true;
//     }
//     return false;
// }

// Smart Pointer Version
bool Library::borrowBook(int userId, int bookId) {
  auto user = findUserById(userId);
  auto book = findBookById(bookId);
  if (user && book && book->getBorrowedBy() == nullptr) {
    user->borrowBook(book);
    return true;
  }
  return false;
}

bool Library::returnBook(int userId, int bookId) {
  auto user = findUserById(userId);
  auto book = findBookById(bookId);
  if (user && book && book->getBorrowedBy() == user) {
    user->returnBook(book);
    return true;
  }
  return false;
}

// Raw Pointer Version
// void Library::listBooks() const {
//     for(auto book : books) {
//         std::cout << "Book ID: " << book->getId()
//                   << ", Title: " << book->getTitle()
//                   << ", Author: " << book->getAuthor();
//         if(book->getBorrowedBy()) {
//             std::cout << ", Borrowed by: " <<
//             book->getBorrowedBy()->getName();
//         } else {
//             std::cout << ", Available";
//         }
//         std::cout << std::endl;
//     }
// }

// void Library::listUsers() const {
//     for(auto user : users) {
//         std::cout << "User ID: " << user->getId()
//                   << ", Name: " << user->getName()
//                   << ", Borrowed Books: ";
//         for(auto book : user->getBorrowedBooks()) {
//             std::cout << book->getTitle() << " (ID: " << book->getId() << "),
//             ";
//         }
//         std::cout << std::endl;
//     }
// }

// Smart Pointer Version
void Library::listBooks() const {
  for (const auto &book : books) {
    std::cout << "Book ID: " << book->getId() << ", Title: " << book->getTitle()
              << ", Author: " << book->getAuthor();
    auto borrower = book->getBorrowedBy();
    if (borrower) {
      std::cout << ", Borrowed by: " << borrower->getName();
    } else {
      std::cout << ", Available";
    }
    std::cout << std::endl;
  }
}

void Library::listUsers() const {
  for (const auto &user : users) {
    std::cout << "User ID: " << user->getId() << ", Name: " << user->getName()
              << ", Borrowed Books: ";
    for (auto book : user->getBorrowedBooks()) {
      std::cout << book->getTitle() << " (ID: " << book->getId() << "), ";
    }
    std::cout << std::endl;
  }
}
