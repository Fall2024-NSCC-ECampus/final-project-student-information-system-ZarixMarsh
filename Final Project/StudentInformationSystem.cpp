#include "StudentInformationSystem.h"
#include <iostream>
#include <algorithm>

// Constructor
StudentInformationSystem::StudentInformationSystem() : weight1(0.25), weight2(0.25), weightFinal(0.50) {}

// Method for adding students
void StudentInformationSystem::addStudent() {
    std::string firstName, lastName;
    int studentNumber;
    double midterm1, midterm2, finalExam;

    std::cout << "Enter student's first name: ";
    std::cin >> firstName;
    std::cout << "Enter student's last name: ";
    std::cin >> lastName;
    std::cout << "Enter student's number: ";
    std::cin >> studentNumber;
    std::cout << "Enter midterm #1 grade: ";
    std::cin >> midterm1;
    std::cout << "Enter midterm #2 grade: ";
    std::cin >> midterm2;
    std::cout << "Enter final exam grade: ";
    std::cin >> finalExam;

    students.emplace_back(firstName, lastName, studentNumber, midterm1, midterm2, finalExam);
    std::cout << "Student added successfully.\n";
}

// Method for printing all students
void StudentInformationSystem::printAllStudents() const {
    std::cout << "List of Students:\n";
    for (const auto& student : students) {
        std::cout << student.firstName << " " << student.lastName << ", ID: " << student.studentNumber
        << ", Grades: " << student.midterm1 << ", " << student.midterm2 << ", " << student.finalExam
        << ", Letter Grade: " << student.letterGrade << "\n";
    }
}

    // Method for sorting the students alphabetically
    void StudentInformationSystem::sortStudents() {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            if (a.lastName == b.lastName)
                return a.firstName < b.firstName;
            return a.lastName < b.lastName;
        });
        std::cout << "Students sorted alphabetically.\n";
    }

    // Method for calculating letter grades
    void StudentInformationSystem::calculateLetterGrades() {
        for (auto& student : students) {
            student.calculateLetterGrade(weight1, weight2, weightFinal);
        }
        std::cout << "Letter grades updated.\n";
    }

    // Method for printing a specific student
    void StudentInformationSystem::printStudent() const {
        int studentNumber;
        std::cout << "Enter student number to search: ";
        std::cin >> studentNumber;

        for (const auto& student : students) {
            if (student.studentNumber == studentNumber) {
                std::cout << "Student: " << student.firstName << " " << student.lastName
                          << ", Grades: " << student.midterm1 << ", " << student.midterm2 << ", " << student.finalExam
                          << ", Letter Grade: " << student.letterGrade << "\n";
                return;
            }
        }
        std::cout << "Student not found.\n";
    }

    // Method for removing a specific student
    void StudentInformationSystem::removeStudent() {
        int studentNumber;
        std::cout << "Enter student number to remove: ";
        std::cin >> studentNumber;

        students.erase(std::remove_if(students.begin(), students.end(),
                                      [studentNumber](const Student& student) {
                                          return student.studentNumber == studentNumber;
                                      }),
                       students.end());
        std::cout << "Student removed if found.\n";
    }

    // Method for deleting all students
    void StudentInformationSystem::deleteAllStudents() {
        students.clear();
        std::cout << "All student data deleted.\n";
    }

    // Method for changing the grade weights
    void StudentInformationSystem::setGradeWeights() {
        std::cout << "Enter weight for midterm #1 (0-1): ";
        std::cin >> weight1;
        std::cout << "Enter weight for midterm #2 (0-1): ";
        std::cin >> weight2;
        weightFinal = 1.0 - (weight1 + weight2);
        std::cout << "Weights updated. Final weight is set to " << weightFinal << ".\n";
    }

    // Method for updating a specific student
void StudentInformationSystem::updateStudent() {
    int studentNumber;
    std::cout << "Enter the student number of the student you want to update: ";
    std::cin >> studentNumber;

    for (auto& student : students) {
        if (student.studentNumber == studentNumber) {
            std::cout << "Updating information for " << student.firstName << " " << student.lastName << "\n";

            std::cout << "Enter new first name (current: " << student.firstName << "): ";
            std::cin >> student.firstName;

            std::cout << "Enter new last name (current: " << student.lastName << "): ";
            std::cin >> student.lastName;

            std::cout << "Enter new student number (current: " << student.studentNumber << "): ";
            std::cin >> student.studentNumber;

            std::cout << "Enter new midterm #1 grade (current: " << student.midterm1 << "): ";
            std::cin >> student.midterm1;

            std::cout << "Enter new midterm #2 grade (current: " << student.midterm2 << "): ";
            std::cin >> student.midterm2;

            std::cout << "Enter new final exam grade (current: " << student.finalExam << "): ";
            std::cin >> student.finalExam;

            std::cout << "Student information updated successfully.\n";
            return;
        }
    }

    std::cout << "Student with number " << studentNumber << " not found.\n";
}