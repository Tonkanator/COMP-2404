#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <ostream>

using namespace std;

class TestClass;

class Student
{
  friend class TestClass;
  friend ostream& operator<<(ostream&, const Student&);
  public:
    Student(string="000000000", string="Hey you!",  float=0.0f);
    Student(const Student&);
    
    bool operator==(const Student&) const;
    float getGPA() const;
    string getNumber() const;
    string getName() const;

  private:
    string  number;
    string  name;
    float   gpa;
};

#endif
