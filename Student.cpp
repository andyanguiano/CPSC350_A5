#include "Student.h"


Student::Student(){
  m_id = 0;
  m_name = "";
  m_level = "";
  m_major = "";
  m_gpa = 0.0;
  m_advisor = 0;
}

Student::Student(int id, string name, string level, string major, double gpa, int advisor){
  m_id = id;
  m_name = name;
  m_level = level;
  m_major = major;
  m_gpa = gpa;
  m_advisor = advisor;
}

Student::~Student(){
  //no pointers to delete
}

void Student::setID(int id){
  m_id = id;
}

int Student::getID(){
  return m_id;
}

void Student::setName(string name){
  m_name = name;
}

string Student::getName(){
  return m_name;
}

void Student::setLevel(string level){
  m_level =level;
}

string Student::getLevel(){
  return m_level;
}

void Student::setMajor(string major){
  m_major = major;
}

string Student::getMajor(){
  return m_major;
}

void Student::setGpa(double gpa){
  m_gpa = gpa;
}
double Student::getGpa(){
  return m_gpa;
}

void Student::setAdvisor(int advisor){
  m_advisor = advisor;
}

int Student::getAdvisor(){
  return m_advisor;
}

int Student::compareTo(Student* s){
  int tempId = s->getID();
  if(m_id > tempId){
    return 0;
  }
  return 1;
}
