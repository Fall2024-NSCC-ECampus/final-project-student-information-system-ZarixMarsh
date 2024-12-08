#include "Student.h"

// Constructor
Student::Student(std::string first, std::string last, int number, double m1, double m2, double fin)
    : firstName(first), lastName(last), studentNumber(number), midterm1(m1), midterm2(m2), finalExam(fin), letterGrade('F') {}

// Calculate the letter grade
char Student::calculateLetterGrade(double weight1, double weight2, double weightFinal) {
    double average = midterm1 * weight1 + midterm2 * weight2 + finalExam * weightFinal;
    if (average > 90) letterGrade = 'A';
    else if (average > 80) letterGrade = 'B';
    else if (average > 70) letterGrade = 'C';
    else if (average > 60) letterGrade = 'D';
    else letterGrade = 'F';
    return letterGrade;
}