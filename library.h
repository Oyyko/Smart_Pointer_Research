#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include <memory>
#include <vector>

class Library {
private:
  // Choose one of the following based on memory management method
  // Raw Pointer Version
  // std::vector<Book*> books;
  // std::vector<User*> users;

  // Smart Pointer Version
  std::vector<std::shared_ptr<Book>> books;
  std::vector<std::shared_ptr<User>> users;

public:
  Library();
  ~Library();

  // Choose one of the following based on memory management method
  // Raw Pointer Version
  // void addBook(Book* book);
  // void addUser(User* user);
  // Book* findBookById(int id) const;
  // User* findUserById(int id) const;

  // Smart Pointer Version
  void addBook(std::shared_ptr<Book> book);
  void addUser(std::shared_ptr<User> user);
  std::shared_ptr<Book> findBookById(int id) const;
  std::shared_ptr<User> findUserById(int id) const;

  // Choose one of the following based on memory management method
  // Raw Pointer Version
  // bool borrowBook(int userId, int bookId);
  // bool returnBook(int userId, int bookId);

  // Smart Pointer Version
  bool borrowBook(int userId, int bookId);
  bool returnBook(int userId, int bookId);

  // Choose one of the following based on memory management method
  // Raw Pointer Version
  // void listBooks() const;
  // void listUsers() const;

  // Smart Pointer Version
  void listBooks() const;
  void listUsers() const;
};

#endif // LIBRARY_H
