#ifndef STUDENTINFORMATIONSYSTEM_H
#define STUDENTINFORMATIONSYSTEM_H

#include "Student.h"
#include <vector>

class StudentInformationSystem {
private:
    std::vector<Student> students;
    double weight1, weight2, weightFinal;

public:
    // Constructor
    StudentInformationSystem();

    // Function declarations
    void addStudent();
    void printAllStudents() const;
    void sortStudents();
    void calculateLetterGrades();
    void printStudent() const;
    void removeStudent();
    void deleteAllStudents();
    void setGradeWeights();
    void updateStudent();
};

#endif // STUDENTINFORMATIONSYSTEM_H