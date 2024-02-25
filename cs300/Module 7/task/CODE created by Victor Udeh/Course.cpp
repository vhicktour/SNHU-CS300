// Course.cpp
// Code created by Victor Udeh
// SNHU-CS300 Final project
// Feb 25, 2024

// Include the header file that contains the declaration of the Course class
#include "Course.h"

// Definition of the Course class constructor
// This constructor initializes a Course object with provided values for its attributes
Course::Course(std::string num, std::string t, std::vector<std::string> prereqs)
    // Member initializer list to directly initialize member variables
    : courseNumber(num), // Initialize courseNumber with the value of num
      title(t), // Initialize title with the value of t
      prerequisites(prereqs) // Initialize prerequisites with the value of prereqs
{} // The body of the constructor is empty because initialization is done using the initializer list
