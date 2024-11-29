#ifndef BOOK_H
#define BOOK_H

#include <memory>
#include <string>

// Forward declaration
class User;

class Book {
private:
  int id;
  std::string title;
  std::string author;

  // Choose one of the following based on memory management method
  // Raw Pointer Version
  // User* borrowedBy;

  // Smart Pointer Version (use std::weak_ptr to avoid circular references)
  std::weak_ptr<User> borrowedBy;

public:
  Book(int id, const std::string &title, const std::string &author);
  ~Book();

  int getId() const;
  std::string getTitle() const;
  std::string getAuthor() const;

  // Raw Pointer Version
  // User* getBorrowedBy() const;

  // Smart Pointer Version
  std::shared_ptr<User> getBorrowedBy() const;

  // Raw Pointer Version
  // void borrowBook(User* user);
  // void returnBook();

  // Smart Pointer Version
  void borrowBook(std::shared_ptr<User> user);
  void returnBook();
};

#endif // BOOK_H
