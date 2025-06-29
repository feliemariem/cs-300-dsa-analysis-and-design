//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Felie Marie Magbanua
// Course      : CS-300 DSA: Analysis and Design
// Version     : 1.0
// Description : Academic Course Planner - Project Two
//               Loads, sorts, and displays course information for advisors.
//               Allows users to look up any course and its prerequisites.
//               Demonstrates the use of hash tables, sorting, and robust user input.
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Define the Course structure, representing a course with its number, title, and prerequisites
struct Course {
    std::string courseNumber;
    std::string courseTitle;
    std::vector<std::string> prerequisites;
};

// Function prototypes for clarity and organization
void loadCoursesFromFile(const std::string& filename, std::unordered_map<std::string, Course>& courses);
void printCourseList(const std::unordered_map<std::string, Course>& courses);
void printCourse(const std::unordered_map<std::string, Course>& courses);
std::string toUpper(const std::string& str);

int main() {
    // Hash table to store all courses with courseNumber as key
    std::unordered_map<std::string, Course> courses;
    bool dataLoaded = false; // Tracks if data has been loaded
    int choice = 0; // Stores the user's menu selection

    std::cout << "Welcome to the course planner." << std::endl;

    // Main menu loop
    while (true) {
        // Display menu options
        std::cout << "1. Load Data Structure." << std::endl;
        std::cout << "2. Print Course List." << std::endl;
        std::cout << "3. Print Course." << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "What would you like to do? ";

        std::string input;
        std::getline(std::cin, input); // Get entire line for input (handles spaces)
        std::stringstream ss(input);
        ss >> choice;

        // Check for invalid input or invalid menu option
        if (ss.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 9)) {
            std::cout << input << " is not a valid option." << std::endl;
            continue; // Return to menu
        }

        if (choice == 1) {
            // Load data structure from file
            std::string filename;
            std::cout << "Please enter the filename of the data file to load: ";
            std::getline(std::cin, filename); // Get file name
            loadCoursesFromFile(filename, courses);
            if (!courses.empty()) {
                dataLoaded = true;
                std::cout << "Courses loaded successfully." << std::endl;
            }
            else {
                std::cout << "No courses loaded. Please check the file and try again." << std::endl;
            }
        }
        else if (choice == 2) {
            // Print course list in alphanumeric order
            if (!dataLoaded) {
                std::cout << "Please load the data structure first (Option 1)." << std::endl;
                continue;
            }
            printCourseList(courses);
        }
        else if (choice == 3) {
            // Print details for a single course
            if (!dataLoaded) {
                std::cout << "Please load the data structure first (Option 1)." << std::endl;
                continue;
            }
            printCourse(courses);
        }
        else if (choice == 9) {
            // Exit the program
            std::cout << "Thank you for using the course planner!" << std::endl;
            break;
        }
    }

    return 0;
}

// Converts a string to uppercase for case-insensitive matching (e.g., csci200 -> CSCI200)
std::string toUpper(const std::string& str) {
    std::string result = str;
    for (auto& ch : result) ch = toupper(ch);
    return result;
}

// Reads and parses courses from the given filename into the courses hash table
void loadCoursesFromFile(const std::string& filename, std::unordered_map<std::string, Course>& courses) {
    courses.clear(); // Clear existing data before loading
    std::ifstream file(filename); // Open the file
    if (!file) {
        std::cout << "Error: Cannot open file '" << filename << "'." << std::endl;
        return;
    }
    std::string line;
    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines
        std::stringstream ss(line);
        std::vector<std::string> tokens;
        std::string token;
        // Split line by commas
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() < 2) {
            std::cout << "Format error: Each line must have at least course number and title." << std::endl;
            continue; // Skip bad line
        }
        Course course;
        course.courseNumber = toUpper(tokens[0]);
        course.courseTitle = tokens[1];
        // Add prerequisites, if any
        for (size_t i = 2; i < tokens.size(); ++i) {
            course.prerequisites.push_back(toUpper(tokens[i]));
        }
        // Insert course into hash table
        courses[course.courseNumber] = course;
    }
}

// Prints all courses (number and title) in alphanumeric order by course number
void printCourseList(const std::unordered_map<std::string, Course>& courses) {
    std::vector<std::string> courseNumbers;
    // Gather all course numbers for sorting
    for (const auto& pair : courses) {
        courseNumbers.push_back(pair.first);
    }
    std::sort(courseNumbers.begin(), courseNumbers.end()); // Alphanumeric sort
    std::cout << "Here is a sample schedule:" << std::endl;
    for (const std::string& num : courseNumbers) {
        std::cout << num << ", " << courses.at(num).courseTitle << std::endl;
    }
}

// Prompts for a course number, then prints the course info and its prerequisites (number & title)
void printCourse(const std::unordered_map<std::string, Course>& courses) {
    std::string input;
    std::cout << "What course do you want to know about? ";
    std::getline(std::cin, input);
    std::string courseNum = toUpper(input); // Standardize input for case-insensitive match

    auto it = courses.find(courseNum);
    if (it == courses.end()) {
        std::cout << "Course not found." << std::endl;
        return;
    }

    const Course& course = it->second;
    std::cout << course.courseNumber << ", " << course.courseTitle << std::endl;

    if (course.prerequisites.empty()) {
        std::cout << "Prerequisites: None" << std::endl;
    }
    else {
        std::cout << "Prerequisites: ";
        // Print each prerequisite with its number and title, if found
        for (size_t i = 0; i < course.prerequisites.size(); ++i) {
            const std::string& prereqNum = course.prerequisites[i];
            auto prereqIt = courses.find(prereqNum);
            if (prereqIt != courses.end()) {
                std::cout << prereqIt->second.courseNumber << ", " << prereqIt->second.courseTitle;
            }
            else {
                // Prerequisite listed in file but not found in loaded data
                std::cout << prereqNum;
            }
            if (i < course.prerequisites.size() - 1) std::cout << "; ";
        }
        std::cout << std::endl;
    }
}
