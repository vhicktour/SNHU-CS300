// Course.h
// Code created by Victor Udeh
// SNHU-CS300 Final project
// Feb 25, 2024

// Guard to prevent multiple inclusions of the header file
#ifndef COURSE_H
#define COURSE_H

// Include necessary libraries
#include <string> // For using the std::string class
#include <vector> // For using the std::vector class

// Define the Course class
class Course {
public:
    // Public member variables
    std::string courseNumber; // Unique identifier for the course, such as "CS300"
    std::string title; // Title of the course, e.g., "Data Structures and Algorithms"
    std::vector<std::string> prerequisites; // List of course numbers that are prerequisites

    // Constructor declaration
    // This constructor initializes a Course object with a number, title, and list of prerequisites
    Course(std::string num, std::string t, std::vector<std::string> prereqs);
};

// End of the guard to prevent multiple inclusions
#endif
