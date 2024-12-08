#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    std::string firstName;
    std::string lastName;
    int studentNumber;
    double midterm1, midterm2, finalExam;
    char letterGrade;

    // Constructor
    Student(std::string first, std::string last, int number, double m1, double m2, double fin);

    // Calculate the letter grade
    char calculateLetterGrade(double weight1, double weight2, double weightFinal);
};

#endif // STUDENT_H
