//CourseLoader.cpp
// Code created by Victor Udeh
// SNHU-CS300 Final project
// Feb 25, 2024

// Include the Course class and necessary C++ libraries for file and string manipulation
#include "Course.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Function to load courses from a specified file into a vector of Course objects
std::vector<Course> loadCoursesFromFile(const std::string& fileName) {
    std::vector<Course> courses; // Vector to hold the loaded courses
    std::ifstream file(fileName); // File stream to read from the specified file
    std::string line; // String to store each line read from the file

    // Print a message indicating the start of the course loading process
    std::cout << "Starting to load courses from file." << std::endl;

    if (!file.is_open()) { // Check if the file failed to open
        std::cerr << "Failed to open file: " << fileName << std::endl; // Print an error message
        return courses; // Return the empty vector if file couldn't be opened
    } else {
        // Print a message indicating the file was successfully opened
        std::cout << "File opened successfully." << std::endl;
    }

    int courseCount = 0; // Variable to keep track of the number of courses loaded
    while (std::getline(file, line)) { // Read the file line by line
        std::stringstream ss(line); // Use a stringstream to parse the line
        std::string courseNumber, title, prereq; // Variables to hold course details
        // Extract course number and title from the line
        std::getline(ss, courseNumber, ',');
        std::getline(ss, title, ',');
        std::vector<std::string> prerequisites; // Vector to hold prerequisites
        // Extract prerequisites from the line
        while (std::getline(ss, prereq, ',')) {
            prerequisites.push_back(prereq); // Add each prerequisite to the vector
        }
        // Create a Course object and add it to the courses vector
        courses.push_back(Course(courseNumber, title, prerequisites));
        
        // Print the details of the loaded course
        std::cout << "Loaded course: " << courseNumber << " - " << title << std::endl;
        courseCount++; // Increment the course count
    }

    // Print the total number of courses loaded
    std::cout << "Total courses loaded: " << courseCount << std::endl;

    return courses; // Return the vector containing all the loaded courses
}
