#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

//student object
class Student{
  public:
    Student(); //default
    Student(int id, string name, string level, string major, double gpa, int advisor); //overlaoded
    ~Student(); //destructor
    //gettters setters
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

    int compareTo(Student* s);//compare student ids

  private:
    int m_id;
    string m_name;
    string m_level;
    string m_major;
    double m_gpa;
    int m_advisor;
};

#endif
