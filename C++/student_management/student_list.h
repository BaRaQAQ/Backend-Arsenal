#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include <vector>
#include "student.h"

class StudentList {
private:
    std::vector<Student> students;
public:
    friend void addStudent(StudentList& list, const std::string& name, int id, double score);
    friend void queryStudent(const StudentList& list, int id);
    friend double calculateAverage(const StudentList& list);
};

#endif