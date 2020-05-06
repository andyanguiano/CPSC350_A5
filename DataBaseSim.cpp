#include "DataBaseSim.h"

DataBaseSim::DataBaseSim(){
  m_students = new BST<Student>();
  m_faculty = new BST<Faculty>();
}

DataBaseSim::DataBaseSim(BST<Student>* students, BST<Faculty>* faculty){
  m_students = students;
  m_faculty = faculty;
}

DataBaseSim::~DataBaseSim(){
  delete m_students;
  delete m_faculty;
}

void DataBaseSim::choices(){
  cout << "MENU. Select the number you would like to preform." << endl;
  cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
  cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
  cout << "3. Find and display student information given the students id" << endl;
  cout << "4. Find and display faculty information given the faculty id" << endl;
  cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
  cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
  cout << "7. Add a new student" << endl;
  cout << "8. Delete a student given the id" << endl;
  cout << "9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member given the id." << endl;
  cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
  cout << "12. Remove an advisee from a faculty member given the ids" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;
  cout << endl;
}

void DataBaseSim::selection(){
  string choice = "";
  while(choice != "14"){
    cout << "Enter input: ";
    cin >> choice;
    cout << endl;

    if(choice == "1"){
      TreeNode<Student>* root = m_students->getRoot();
      if(root == NULL){
        cout << "Students database is empty." << endl;
      }else{
        printStudents(root);
      }
    }else if(choice == "2"){
      TreeNode<Faculty>* root = m_faculty->getRoot();
      if(root == NULL){
        cout << "Faculty database is empty" << endl;
      }else{
        printFaculty(root);
      }
    }else if(choice == "3"){
      int id = 0;
      cout << "ID of the student: ";
      cin >> id;
      cout << endl;
      Student* s = m_students->search(id);
      if(s != NULL){
        studentInfo(s);
      }else{
        cout << "This student does not exist. Try again." << endl;
        cout << endl;
      }
    }else if(choice == "4"){
      int id = 0;
      cout << "ID of the faculty member: ";
      cin >> id;
      Faculty* f = m_faculty->search(id);
      if(f != NULL){
        facultyInfo(f);
      }else{
        cout << "This faculty member does not exist. Try again." << endl;
        cout << endl;
      }
    }else if(choice == "5"){
      int id = 0;
      cout << "ID of the student: ";
      cin >> id;
      cout << endl;
      Student* s = m_students->search(id);
      if(s != NULL){
        advisorInfo(s);
      }else{
        cout << "This student does not exist. Try again." << endl;
        cout << endl;
      }
    }else if(choice == "6"){
      int id = 0;
      cout << "ID of the student: ";
      cin >> id;
      cout << endl;
      Faculty* f = m_faculty->search(id);
      if(f != NULL){
        adviseeInfo(f);
      }else{
        cout << "This faculty member does not exist. Try again." << endl;
        cout << endl;
      }
    }else if(choice == "7"){
      
    }else if(choice == "8"){

    }else if(choice == "9"){

    }else if(choice == "10"){

    }else if(choice == "11"){

    }else if(choice == "12"){

    }else if(choice == "13"){

    }else{
      cout << "That was not an option please try again." << endl;
    }




  }
}

void DataBaseSim::printStudents(TreeNode<Student>* s){
  cout << "Here are all of the Students: " << endl;
  cout << endl;
  printStudents(s->left);
  Student* student = s->data;
  cout << "ID: " << student->getID() << endl;
  cout << "Name: " << student->getName() << endl;
  cout << "Level: " << student->getLevel() << endl;
  cout << "Major: " << student->getMajor() << endl;
  cout << "GPA: " << student->getGpa() << endl;
  cout << "Advisor: " << student->getAdvisor() << endl;
  cout << endl;
  printStudents(s->right);
}

void DataBaseSim::printFaculty(TreeNode<Faculty>* f){
  cout << "Here are all the faculty members: " << endl;
  cout << endl;
  printFaculty(f->left);
  Faculty* faculty = f->data;
  cout << "ID: " << faculty->getID() << endl;
  cout << "Name: " << faculty->getName() << endl;
  cout << "Level: " << faculty->getLevel() << endl;
  cout << "Department: " << faculty->getDepartment() << endl;
  cout << "List of advisees ID: ";
  LinkedList<int>* advisee = faculty->getAdvisees();
  if(!advisee->isEmpty()){
    advisee->printList();
  }
  cout << endl;
  printFaculty(f->right);
}

void DataBaseSim::studentInfo(Student* s){
  cout << "Here is the students information: " << endl;
  cout << "ID: " << s->getID() << endl;
  cout << "Name: " << s->getName() << endl;
  cout << "Level: " << s->getLevel() << endl;
  cout << "Major: " << s->getMajor() << endl;
  cout << "GPA: " << s->getGpa() << endl;
  cout << "Advisor: " << s->getAdvisor() << endl;
  cout << endl;
}

void DataBaseSim::facultyInfo(Faculty* f){
  cout << "Here is the faculty members information: " << endl;
  cout << "ID: " << f->getID() << endl;
  cout << "Name: " << f->getName() << endl;
  cout << "Level: " << f->getLevel() << endl;
  cout << "Department: " << f->getDepartment() << endl;
  cout << "List of advisees ID: ";
  LinkedList<int>* advisee = f->getAdvisees();
  if(!advisee->isEmpty()){
    advisee->printList();
  }
  cout << endl;
}

void DataBaseSim::advisorInfo(Student* s){
  cout << "The students advisor: " << s->getAdvisor() << endl;
  Faculty* f = m_faculty->search(s->getAdvisor());
  if(f != NULL){
    facultyInfo(f);
  }else{
    cout << "Faculty member is not longer in the database." << endl;
  }
}

void DataBaseSim::adviseeInfo(Faculty* f){
  LinkedList<int>* advisee = f->getAdvisees();
  ListNode<int>* node = advisee->front;
  while(node != NULL){
    int studentID = node->data;
    Student* student = m_students->search(studentID);
    studentInfo(student);
    node->next;
  }
  cout << endl;
}

void DataBaseSim::addStudent(){

}
void DataBaseSim::deleteStudent(){}
void DataBaseSim::addFaculty(){}
void DataBaseSim::deleteFaculty(){}
void DataBaseSim::changeAdvisor(){}
void DataBaseSim::removeAdvisee(){}
void DataBaseSim::rollBack(){}
