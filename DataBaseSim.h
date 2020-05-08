#include "Student.h"
#include "Faculty.h"
#include "BST.h"

class DataBaseSim{
  public:
    DataBaseSim();
    DataBaseSim(BST<Student>* students, BST<Faculty>* faculty);
    ~DataBaseSim();

    void choices();
    void selection();
    void printStudents(TreeNode<Student>* s); //Print all students and their information (sorted by ascending id #)
    void printFaculty(TreeNode<Faculty>* f); //Print all faculty and their information (sorted by ascending id #)
    void studentInfo(Student* s); //Find and display student information given the students id
    void facultyInfo(Faculty* f); //Find and display faculty information given the faculty id
    void advisorInfo(Student* s); //Given a student’s id, print the name and info of their faculty advisor
    void adviseeInfo(Faculty* f); //Given a faculty id, print ALL the names and info of his/her advisees.
    void addStudent(); //Add a new student
    void deleteStudent(); //Delete a student given the id
    void addFaculty(); //Add a new faculty member
    void deleteFaculty(); //Delete a faculty member given the id.
    void changeAdvisor(); //Change a student’s advisor given the student id and the new faculty id.
    void removeAdvisee(); //Remove an advisee from a faculty member given the ids
    void rollBack(); //Rollback

    BST<Student>* getStudetTree();
    BST<Faculty>* getFacultyTree();


  private:
    BST<Student>* m_students;
    BST<Faculty>* m_faculty;

};
