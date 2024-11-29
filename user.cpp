#include "User.h"
#include "Book.h"

// Raw Pointer Version Constructor
// User::User(int id, const std::string& name)
//     : id(id), name(name), borrowedBooks() {}

// Smart Pointer Version Constructor
User::User(int id, const std::string &name)
    : id(id), name(name), borrowedBooks() {}

User::~User() {
  // Raw Pointer Version: No need to delete borrowedBooks as Books are managed
  // by Library

  // Smart Pointer Version: No manual deletion required
}

int User::getId() const { return id; }

std::string User::getName() const { return name; }

// Raw Pointer Version
// const std::vector<Book*>& User::getBorrowedBooks() const {
//     return borrowedBooks;
// }

// Smart Pointer Version
const std::vector<std::shared_ptr<Book>> &User::getBorrowedBooks() const {
  return borrowedBooks;
}

// Raw Pointer Version
// void User::borrowBook(Book* book) {
//     borrowedBooks.push_back(book);
//     book->borrowBook(this);
// }

// Smart Pointer Version
void User::borrowBook(std::shared_ptr<Book> book) {
  borrowedBooks.push_back(book);
  book->borrowBook(shared_from_this());
}

// Raw Pointer Version
// void User::returnBook(Book* book) {
//     for(auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
//         if(*it == book) {
//             borrowedBooks.erase(it);
//             book->returnBook();
//             break;
//         }
//     }
// }

// Smart Pointer Version
void User::returnBook(std::shared_ptr<Book> book) {
  for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
    if (*it == book) {
      borrowedBooks.erase(it);
      book->returnBook();
      break;
    }
  }
}
