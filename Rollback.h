#include "GenStack.h"
#include "Student.h"
#include "Faculty.h"
#include "ActionType.h"

//rollback action
class Rollback{
  public:
    Rollback(); //constructor
    ~Rollback(); //destructor

    void addStudentAction(Student* s, string type); //adds to stacks SEG FAULT
    void addFacultyAction(Faculty* f, string type); //adds to stacks SEG FAULT

    string undo(); //sees last action

    Student* popStudent(); //removes last student
    Faculty* popFaculty(); //removes last faculty

    bool isEmpty(); //checks if empty

  private:
    GenStack<Student>* m_studentStack;
    GenStack<Faculty>* m_facultyStack;
    GenStack<ActionType>* m_actionStack;
};
