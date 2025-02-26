#include "student.h"
#include "student_list.h"
#include <iostream>

// 添加学生信息
void addStudent(StudentList& list, const std::string& name, int id, double score) {
    Student student = {name, id, score};
    list.students.push_back(student);
}

// 查询学生成绩
void queryStudent(const StudentList& list, int id) {
    for (const auto& student : list.students) {
        if (student.id == id) {
            std::cout << "姓名: " << student.name << ", 成绩: " << student.score << std::endl;
            return;
        }
    }
    std::cout << "未找到该学生" << std::endl;
}

// 计算平均成绩
double calculateAverage(const StudentList& list) {
    if (list.students.empty()) {
        return 0;
    }

    double totalScore = 0;
    for (const auto& student : list.students) {
        totalScore += student.score;
    }

    return totalScore / list.students.size();
}