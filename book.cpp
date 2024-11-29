#include "Book.h"
#include "User.h"

// Raw Pointer Version Constructor
// Book::Book(int id, const std::string& title, const std::string& author)
//     : id(id), title(title), author(author), borrowedBy(nullptr) {}

// Smart Pointer Version Constructor
Book::Book(int id, const std::string &title, const std::string &author)
    : id(id), title(title), author(author), borrowedBy() {}

Book::~Book() {
  // Raw Pointer Version: No need to delete borrowedBy as User's lifecycle is
  // managed by Library

  // Smart Pointer Version: No manual deletion required
}

int Book::getId() const { return id; }

std::string Book::getTitle() const { return title; }

std::string Book::getAuthor() const { return author; }

// Raw Pointer Version
// User* Book::getBorrowedBy() const {
//     return borrowedBy;
// }

// Smart Pointer Version
std::shared_ptr<User> Book::getBorrowedBy() const {
  return borrowedBy.lock(); // Attempt to promote to std::shared_ptr
}

// Raw Pointer Version
// void Book::borrowBook(User* user) {
//     borrowedBy = user;
// }

// Smart Pointer Version
void Book::borrowBook(std::shared_ptr<User> user) {
  borrowedBy = user; // std::weak_ptr does not increase reference count
}

// Raw Pointer Version
// void Book::returnBook() {
//     borrowedBy = nullptr;
// }

// Smart Pointer Version
void Book::returnBook() {
  borrowedBy.reset(); // Remove the association
}
