#include "GenStack.h"
#include "Student.h"
#include "Faculty.h"
#include "ActionType.h"

class Rollback{
  public:
    Rollback();
    ~Rollback();

    void addStudentAction(Student* s, string type);
    void addFacultyAction(Faculty* f, string type);

    string undo();

    Student* popStudent();
    Faculty* popFaculty();

    bool isEmpty();

  private:
    GenStack<Student>* m_studentStack;
    GenStack<Faculty>* m_facultyStack;
    GenStack<ActionType>* m_actionStack;
};
