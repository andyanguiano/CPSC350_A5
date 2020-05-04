#include "Faculty.h"

Faculty::Faculty(){
  m_id = 0;
  m_name = "";
  m_level = "";
  m_department = "";
  m_advisees = NULL;
}

Faculty::Faculty(int id, string name, string level, string department){
  m_id = id;
  m_name = name;
  m_level = level;
  m_department = department;
}

Faculty::~Faculty(){
  m_advisees = NULL;
  delete m_advisees;
}

void Faculty::setID(int id){
  m_id = id;
}

int Faculty::getID(){
  return m_id;
}

void Faculty::setName(string name){
  m_name = name;
}

string Faculty::getName(){
  return m_name;
}

void Faculty::setLevel(string level){
  m_level = level;
}

string Faculty::getLevel(){
  return m_level;
}

void Faculty::setDepartment(string department){
  m_department = department;
}

string Faculty::getDepartment(){
  return m_department;
}

void Faculty::setAdvisees(LinkedList<int>* advisees){
  m_advisees = advisees;
}

LinkedList<int>* Faculty::getAdvisees(){
  return m_advisees;
}

int Faculty::comapareTo(Faculty *f){
  int tempId = f->getID();
  if(m_id > tempId){
    return 0;
  }
  return 1;
}
