#include <iostream>

#include "StudentInformationSystem.h"

int main() {
    StudentInformationSystem system;
    int choice;

    do {
        std::cout << "\nStudent Information System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Print All Students\n";
        std::cout << "3. Sort Students Alphabetically\n";
        std::cout << "4. Calculate Letter Grades\n";
        std::cout << "5. Print Specific Student\n";
        std::cout << "6. Remove Student\n";
        std::cout << "7. Delete All Students\n";
        std::cout << "8. Set Grade Weights\n";
        std::cout << "9. Exit\n";
        std::cout << "10. Update Student Information\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system.addStudent();
            break;
            case 2:
                system.printAllStudents();
            break;
            case 3:
                system.sortStudents();
            break;
            case 4:
                system.calculateLetterGrades();
            break;
            case 5:
                system.printStudent();
            break;
            case 6:
                system.removeStudent();
            break;
            case 7:
                system.deleteAllStudents();
            break;
            case 8:
                system.setGradeWeights();
            break;
            case 9:
                std::cout << "Exiting program.\n";
            break;
            case 10:
                system.updateStudent();
            break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}