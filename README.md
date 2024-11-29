# Library Management System Experiment

## Overview

This repository provides a **skeleton code framework** for implementing a simple **Library Management System** in C++. The purpose of this experiment is to evaluate whether the adoption of smart pointers (`std::unique_ptr` and `std::shared_ptr`) in C++ improves developer productivity and enhances code safety compared to traditional manual memory management using raw pointers.

Participants are required to implement the system using either raw pointers or smart pointers, perform various programming tasks, and provide feedback through surveys and interviews.

## Getting Started

### Prerequisites

- **C++ Compiler**: Ensure you have a C++11 compliant compiler installed (e.g., `g++`, `clang++`).
- **Valgrind**: For memory error detection.
- **Static Analysis Tools**: Optional but recommended (e.g., `cppcheck`, `Clang-Tidy`).

### Compilation

Navigate to the project directory and compile the source files using the following command:

```bash
g++ -std=c++11 main.cpp Book.cpp User.cpp Library.cpp -o LibraryManagementSystem

Running the Program
Execute the compiled program:

bash
Copy code
./LibraryManagementSystem
Interactive Menu
Upon running, you will be presented with a simple command-line interface:
Library Management System
1. List Books
2. List Users
3. Borrow Book
4. Return Book
5. Exit
Enter choice:
Follow the prompts to interact with the system.
```

## Implementation Tasks

### Task 1: Implement Using Raw Pointers

1. **Understand the Code Structure**: Familiarize yourself with the provided classes (`Book`, `User`, `Library`) and their interactions.

2. Implement Functionality

   - **Add Books and Users**: Implement `Library::addBook` and `Library::addUser` methods using raw pointers.
   - **Borrow and Return Books**: Implement `Library::borrowBook` and `Library::returnBook` methods managing relationships with raw pointers.
   - **Track Book Status**: Implement methods to display whether a book is available or borrowed, and by whom.

3. Memory Management

   - **Destructor Implementation**: Implement the `Library` destructor to manually delete all dynamically allocated `Book` and `User` objects to prevent memory leaks.

4. Testing

   - Compile and run the program.

   - Use Valgrind to check for memory leaks:

     ```
     bash
     
     
     Copy code
     valgrind --leak-check=full ./LibraryManagementSystem
     ```

   - Use static analysis tools to evaluate code quality:

     ```
     bash
     
     
     Copy code
     cppcheck .
     clang-tidy *.cpp *.h -- -std=c++11
     ```

### Task 2: Implement Using Smart Pointers

1. Modify the Code to Use Smart Pointers

   - Replace raw pointers with `std::unique_ptr` or `std::shared_ptr` as appropriate in `Book`, `User`, and `Library` classes.
   - Update class member variables and method signatures accordingly.

2. Avoid Circular References

   - Use `std::weak_ptr` in the `Book` class to reference `User` objects to prevent memory leaks due to circular dependencies.
   - Ensure that `User` inherits from `std::enable_shared_from_this<User>` to safely create `std::shared_ptr<User>` instances within member functions.

3. Simplify Memory Management

   - Remove manual `delete` operations as smart pointers automatically manage memory.

4. Testing

   - Compile and run the program.

   - Use Valgrind to ensure there are no memory leaks:

     ```
     valgrind --leak-check=full ./LibraryManagementSystem
     ```

   - Use static analysis tools to evaluate code quality:

     ```
     cppcheck .
     clang-tidy *.cpp *.h -- -std=c++11
     ```

### Task 3: Evaluation and Comparison

1. Measure Performance
   - Record the time taken to implement and run tasks using both memory management methods.
   - Note the number of memory-related errors detected by Valgrind.
   - Assess code quality based on static analysis reports.
2. Provide Feedback
   - Complete the provided questionnaire to share your experiences, challenges, and preferences.
   - Participate in interviews if required.

## Memory Management Considerations

### Raw Pointers

- Pros
  - Direct control over memory allocation and deallocation.
  - Potentially lower overhead compared to smart pointers.
- Cons
  - Higher risk of memory leaks and dangling pointers.
  - Requires meticulous manual management.

### Smart Pointers

- Pros
  - Automatic memory management reduces the risk of leaks and dangling pointers.
  - Simplifies ownership semantics.
- Cons
  - Slight performance overhead due to reference counting (`std::shared_ptr`).
  - Potential for circular references if not carefully managed.

## Best Practices

- **Consistent Ownership**: Clearly define ownership semantics to avoid confusion and memory issues.
- **Avoid Circular References**: Use `std::weak_ptr` to break cycles in ownership.
- **Use `std::make_shared` and `std::make_unique`**: These functions provide exception safety and optimize memory allocation.
- **Leverage RAII**: Ensure that resource acquisition is tied to object lifetime for automatic management.

## Support

If you encounter any issues or have questions during the experiment, please reach out to the project coordinator or consult the provided documentation.



