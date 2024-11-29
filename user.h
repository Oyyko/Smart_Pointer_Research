#ifndef USER_H
#define USER_H

#include <memory>
#include <string>
#include <vector>

// Forward declaration
class Book;

// If using Smart Pointer Version, inherit from std::enable_shared_from_this
class User : public std::enable_shared_from_this<User> {
private:
  int id;
  std::string name;

  // Choose one of the following based on memory management method
  // Raw Pointer Version
  // std::vector<Book*> borrowedBooks;

  // Smart Pointer Version
  std::vector<std::shared_ptr<Book>> borrowedBooks;

public:
  User(int id, const std::string &name);
  ~User();

  int getId() const;
  std::string getName() const;

  // Raw Pointer Version
  // const std::vector<Book*>& getBorrowedBooks() const;

  // Smart Pointer Version
  const std::vector<std::shared_ptr<Book>> &getBorrowedBooks() const;

  // Raw Pointer Version
  // void borrowBook(Book* book);
  // void returnBook(Book* book);

  // Smart Pointer Version
  void borrowBook(std::shared_ptr<Book> book);
  void returnBook(std::shared_ptr<Book> book);
};

#endif // USER_H
