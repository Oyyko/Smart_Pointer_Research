# Library Management System Experiment Questionnaire

**Participant ID:** P003
 **Date:** 2024-04-22

**Instructions:**
 Thank you for participating in this experiment. Please answer the following questions based on your experience implementing the Library Management System using both raw pointers and smart pointers in C++. Your responses will remain confidential and will be used solely for research purposes. There are no right or wrong answers; we are interested in your honest opinions and experiences.

------

## Section 1: General Experience

1. **Overall, how would you rate your experience with using raw pointers in C++ for memory management?**
   - Very Difficult
   - Difficult
   - Neutral x
   - Easy
   - Very Easy
2. **Overall, how would you rate your experience with using smart pointers (`std::unique_ptr` and `std::shared_ptr`) in C++ for memory management?**
   - Very Difficult
   - Difficult
   - Neutral
   - Easy x
   - Very Easy
3. **How confident did you feel managing memory manually with raw pointers?**
   - Not Confident at All
   - Slightly Confident
   - Moderately Confident
   - Very Confident x
   - Extremely Confident
4. **How confident did you feel managing memory automatically with smart pointers?**
   - Not Confident at All
   - Slightly Confident
   - Moderately Confident
   - Very Confident
   - Extremely Confident x

------

## Section 2: Task-Specific Questions

1. **How clear were the instructions provided for implementing the library management system using raw pointers?**

   - Very Unclear
   - Unclear
   - Neutral
   - Clear x
   - Very Clear

2. **How clear were the instructions provided for implementing the library management system using smart pointers?**

   - Very Unclear
   - Unclear
   - Neutral
   - Clear
   - Very Clear x

3. **Did you encounter any challenges while using raw pointers? Please describe them.**
    *Open-Ended Response*

   Managing object lifetimes was tricky, especially ensuring that all pointers were properly deleted to avoid memory leaks.

------

1. **Did you encounter any challenges while using smart pointers? Please describe them.**
    *Open-Ended Response*

   Understanding when to use `unique_ptr` versus `shared_ptr` was initially confusing, leading to some misuse in the project.

------

1. **How did using smart pointers impact your task completion time compared to using raw pointers?**
   - Significantly Increased Time
   - Somewhat Increased Time
   - No Change
   - Somewhat Decreased Time x
   - Significantly Decreased Time
2. **How did using smart pointers impact the number of memory-related errors (e.g., memory leaks, dangling pointers) in your code compared to using raw pointers?**
   - Significantly Increased Errors
   - Somewhat Increased Errors
   - No Change
   - Somewhat Decreased Errors x
   - Significantly Decreased Errors

------

## Section 3: Comparative Feedback

1. **Which memory management method did you find easier to use?**

   - Raw Pointers
   - Smart Pointers x
   - No Preference

2. **Which memory management method do you believe reduces the likelihood of memory-related errors?**

   - Raw Pointers
   - Smart Pointers x
   - No Difference

3. **Which memory management method do you feel enhances code readability and maintainability?**

   - Raw Pointers
   - Smart Pointers x
   - No Difference

4. **Do you prefer using smart pointers over raw pointers? Why or why not?**
    *Open-Ended Response*

   Yes, because smart pointers handle memory management automatically, reducing the risk of errors and making the code cleaner.

------

1. **What do you think are the main advantages of using smart pointers in C++?**
    *Open-Ended Response*

   They prevent memory leaks and make the code easier to maintain by automatically managing object lifetimes.

------

1. **What improvements, if any, would you suggest for the smart pointer implementation in this experiment?**
    *Open-Ended Response*

   Providing more examples and best practices on when to use each type of smart pointer would be helpful.

------

## Section 4: Additional Comments

1. **Is there anything else you would like to share about your experience with raw pointers or smart pointers in this experiment?**
    *Open-Ended Response*

   Overall, smart pointers streamlined the development process, though a deeper understanding of their different types can enhance their effectiveness.

------

**Thank you for your participation and valuable feedback!**

