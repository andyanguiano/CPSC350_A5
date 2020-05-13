#include "Rollback.h"

Rollback::Rollback(){
  m_studentStack = new GenStack<Student>(5);
  m_facultyStack = new GenStack<Faculty>(5);
  m_actionStack = new GenStack<ActionType>(5);
}

Rollback::~Rollback(){
  delete m_studentStack;
  delete m_facultyStack;
  delete m_actionStack;
}

void Rollback::addStudentAction(Student* s, string type){
  //need to pop everything then delete top and push ll again to add
  if(m_actionStack->isFull()){
    GenStack<ActionType>* temp = new GenStack<ActionType>(5);
    for(int i = 0; i < 5; ++i){
      temp->push(m_actionStack->pop());
    }
    temp->pop();
    for(int i = 0; i < 4; ++i){
      m_actionStack->push(temp->pop());
    }
  }
  m_studentStack->push(s);
  ActionType* action = new ActionType(type);
  m_actionStack->push(action);
}

void Rollback::addFacultyAction(Faculty* f, string type){
  //SEG FAULT
  if(m_actionStack->isFull()){
    GenStack<ActionType>* temp = new GenStack<ActionType>(5);
    for(int i = 0; i < 5; ++i){
      temp->push(m_actionStack->pop());
    }
    temp->pop();
    for(int i = 0; i < 4; ++i){
      m_actionStack->push(temp->pop());
    }
  }
  m_facultyStack->push(f);
  ActionType* action = new ActionType(type);
  m_actionStack->push(action);

}

string Rollback::undo(){
  ActionType* at = m_actionStack->pop();
  string action = at->getType();
  return action;
}

Student* Rollback::popStudent(){
  return m_studentStack->pop();
}

Faculty* Rollback::popFaculty(){
  return m_facultyStack->pop();
}

bool Rollback::isEmpty(){
  return m_actionStack->isEmpty();
}
