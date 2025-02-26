#include "student.h"
#include "student_list.h"
#include <iostream>

int main() {
    StudentList students;

    // 添加学生信息
    addStudent(students, "Alice", 1, 85);
    addStudent(students, "Bob", 2, 90);

    // 查询学生成绩
    queryStudent(students, 1);

    // 计算平均成绩
    std::cout << "平均成绩: " << calculateAverage(students) << std::endl;

    return 0;
}