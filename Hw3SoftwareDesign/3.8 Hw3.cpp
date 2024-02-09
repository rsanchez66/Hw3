#include <iostream>
#include <vector>
#include <algorithm>


struct Student {
    std::string name;
    int grade;
};


// Determine the grade
void findGradeQuartiles(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade; // Sort students by grade in ascending order
    });


    int n = students.size();
    int q1_index = n * 0.25;
    int q2_index = n * 0.50;
    int q3_index = n * 0.75;


    int q1_grade = students[q1_index].grade;
    int q2_grade = students[q2_index].grade;
    int q3_grade = students[q3_index].grade;


    std::cout << "Grade Quartiles:\n";
    std::cout << "Q1 (25th percentile): " << q1_grade << std::endl;
    std::cout << "Q2 (50th percentile): " << q2_grade << std::endl;
    std::cout << "Q3 (75th percentile): " << q3_grade << std::endl;
}


int main() {
    std::vector<Student> students = {
        {"John", 85},
        {"Alice", 70},
        {"Bob", 60},
        {"Emily", 92},
        {"Michael", 78},
        {"Sophia", 88},
        {"David", 65}
    };


    findGradeQuartiles(students);


    return 0;
}