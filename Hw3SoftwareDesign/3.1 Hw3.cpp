#include <iostream>
#include <cstdlib>


// Define the student struct
struct Student {
    int student_id;
    float grade;
};


// sorting by grade
int compare_by_grade(const void *a, const void *b) {
    const Student *student_a = static_cast<const Student*>(a);
    const Student *student_b = static_cast<const Student*>(b);


    if (student_a->grade < student_b->grade) return -1;
    if (student_a->grade > student_b->grade) return 1;
    return 0;
}


// sorting by student ID
int compare_by_id(const void *a, const void *b) {
    const Student *student_a = static_cast<const Student*>(a);
    const Student *student_b = static_cast<const Student*>(b);


    return student_a->student_id - student_b->student_id;
}


int main() {
    // Create an array of students
    Student students[] = {
        {101, 85.5},
        {102, 78.2},
        {103, 92.7},
        {104, 67.8},
        {105, 89.3}
    };
    int num_students = sizeof(students) / sizeof(students[0]);


    // Sorting by grade
    qsort(students, num_students, sizeof(Student), compare_by_grade);


    // sorted by grade
    std::cout << "Sorted by grade:" << std::endl;
    for (int i = 0; i < num_students; ++i) {
        std::cout << "Student ID: " << students[i].student_id << ", Grade: " << students[i].grade << std::endl;
    }


    // Sorting by student ID
    qsort(students, num_students, sizeof(Student), compare_by_id);


    // sorted array by student ID
    std::cout << "\nSorted by student ID:" << std::endl;
    for (int i = 0; i < num_students; ++i) {
        std::cout << "Student ID: " << students[i].student_id << ", Grade: " << students[i].grade << std::endl;
    }


    return 0;
}