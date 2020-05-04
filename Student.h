#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student{
  public:
    Student();
    Student(int id, string name, string level, string major, double gpa, int advisor);
    ~Student();

    void setID(int id);
    int getID();

    void setName(string name);
    string getName();

    void setLevel(string level);
    string getLevel();

    void setMajor(string major);
    string getMajor();

    void setGpa(double gpa);
    double getGpa();

    void setAdvisor(int advisor);
    int getAdvisor();

    int compareTo(Student* s);

  private:
    int m_id;
    string m_name;
    string m_level;
    string m_major;
    double m_gpa;
    int m_advisor;
};

#endif
