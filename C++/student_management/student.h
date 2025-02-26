#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// 定义学生结构体
struct Student {
    std::string name;
    int id;
    double score;
};

// 函数声明
void addStudent(class StudentList& list, const std::string& name, int id, double score);
void queryStudent(const class StudentList& list, int id);
double calculateAverage(const class StudentList& list);

#endif