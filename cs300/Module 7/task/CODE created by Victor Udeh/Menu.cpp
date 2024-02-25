// Menu.cpp
// Code created by Victor Udeh
// SNHU-CS300 Final project
// Feb 25, 2024

// Include the Course class definition and necessary libraries
#include "Course.h"
#include <iostream>
#include <string>
#include <vector>

// Declaration of functions used in this file
std::vector<Course> loadCoursesFromFile(const std::string& fileName);
void printCourses(const std::vector<Course>& courses);
void printCourseInfo(const std::vector<Course>& courses, const std::string& courseNumber);

int main() {
    std::vector<Course> courses; // Vector to store courses loaded from a file
    int choice = 0; // Variable to store the user's menu choice

    // Display the author's name at the start of the program
    std::cout << "Author's Name: Victor Udeh\n\n";

    // Main loop to show menu and process user input
    while (choice != 4) {
        // Display menu options
        std::cout << "1. Load Data Structure\n";
        std::cout << "2. Print Course List\n";
        std::cout << "3. Print Course\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Read user's choice

        // Process user's choice using a switch statement
        switch (choice) {
            case 1: { // Load courses from a file
                std::string fileName;
                std::cout << "Enter file name: ";
                std::cin >> fileName; // Prompt for and read the file name
                courses = loadCoursesFromFile(fileName); // Load courses from the file
                break;
            }
            case 2: // Print all courses loaded
                printCourses(courses);
                break;
            case 3: { // Print information for a specific course
                std::string courseNumber;
                std::cout << "Enter course number: ";
                std::cin >> courseNumber; // Prompt for and read the course number
                printCourseInfo(courses, courseNumber); // Print info for the specified course
                break;
            }
            case 4: // Exit the program
                std::cout << "Exiting program." << std::endl;
                break;
            default: // Handle invalid options
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0; // End of program
}

// Function to print all courses in the vector
void printCourses(const std::vector<Course>& courses) {
    if (courses.empty()) { // Check if the courses vector is empty
        std::cout << "No courses loaded." << std::endl;
        return;
    }
    for (const Course& course : courses) { // Iterate through each course and print its info
        std::cout << course.courseNumber << " - " << course.title << std::endl;
    }
}

// Function to print detailed information about a specific course
void printCourseInfo(const std::vector<Course>& courses, const std::string& courseNumber) {
    bool found = false; // Flag to track if the course is found
    for (const Course& course : courses) { // Iterate through courses to find the matching one
        if (course.courseNumber == courseNumber) {
            // If found, print course details
            std::cout << "Course Number: " << course.courseNumber << std::endl;
            std::cout << "Title: " << course.title << std::endl;
            std::cout << "Prerequisites: ";
            if (course.prerequisites.empty()) { // Check if there are no prerequisites
                std::cout << "None";
            } else {
                // Print all prerequisites
                for (const std::string& prereq : course.prerequisites) {
                    std::cout << prereq << " ";
                }
            }
            std::cout << std::endl;
            found = true; // Mark as found
            break; // Exit the loop once the course is found
        }
    }
    if (!found) { // If the course was not found, print a not found message
        std::cout << "Course with number " << courseNumber << " not found." << std::endl;
    }
}
