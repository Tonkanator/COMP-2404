#include "Algorithms.h"

Algorithms::Algorithms() {}

Algorithms::~Algorithms() {}

// add a new Student object to your data structure
void Algorithms::addStudent(const string& number, const string& name, float gpa) {
    students.push_back(Student(number, name, gpa));
}

// v is a vector that is passed in.
// copy or add all passing Students to v
// passing == (gpa >= 6.0)
void Algorithms::getPassingStudents(vector<Student>& v) {
    for (const auto& student : students) {
        if (student.getGPA() >= 6.0) {
            v.push_back(student);
        }
    }
}

// v is a vector that is passed in.
// copy or add all Students to v in sorted order by 
// student number
void Algorithms::sortByNumber(vector<Student>& v) {
    v = students;
    sort(v.begin(), v.end(), [](const Student& a, const Student& b) {
        return a.getNumber() < b.getNumber();
    });
}

// v is a vector that is passed in.
// copy or add all Students to v in sorted order by 
// name
void Algorithms::sortByName(vector<Student>& v) {
    v = students;
    sort(v.begin(), v.end(), [](const Student& a, const Student& b) {
        return a.getName() < b.getName();
    });
}

// assign the Student with the highest gpa to stuIt
// (as an iterator)
bool Algorithms::highestGpa(vector<Student>::iterator& stuIt) {
    if (students.empty()) {
        return false;
    }
    
    auto maxIt = students.begin();
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getGPA() > maxIt->getGPA()) {
            maxIt = it;
        }
    }
    
    stuIt = maxIt;
    return true;
}

// if a Student with the name 'name' exists
// assign that Student to stuIt (as an iterator)
// and return true, otherwise return false
bool Algorithms::findStudent(const string& name, vector<Student>::iterator& stuIt) {
    auto maxIt = students.begin();
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getName() == name) {
            stuIt = it;
            return true;
        }
    }

    return false;
}