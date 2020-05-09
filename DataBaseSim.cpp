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
    cout << endl;
    choices();
    cout << "Enter input: ";
    cin >> choice;
    cout << endl;

    if(choice == "1"){
      TreeNode<Student>* root = m_students->getRoot();
      if(root == NULL){
        cout << "Students database is empty." << endl;
        cout << endl;
      }else{
        cout << "Here are all of the Students: " << endl;
        printStudents(root);
      }
    }else if(choice == "2"){
      TreeNode<Faculty>* root = m_faculty->getRoot();
      if(root == NULL){
        cout << "Faculty database is empty" << endl;
        cout << endl;
      }else{
        cout << "Here are all the faculty members: " << endl;
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
      cout << "ID of the faculty member: ";
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
      addStudent();
    }else if(choice == "8"){
      if(m_students->isEmpty()){
        cout << "There are no students to delete." << endl;
      }else{
        deleteStudent();
      }
    }else if(choice == "9"){
      addFaculty();
    }else if(choice == "10"){
      if(m_faculty->isEmpty()){
        cout << "There are no faculty members to delete" << endl;
        cout << endl;
      }else{
        deleteFaculty();
      }
    }else if(choice == "11"){
      changeAdvisor();
    }else if(choice == "12"){
      removeAdvisee();
    }else if(choice == "13"){

    }else if(choice == "14"){
      cout << "Saving Changes..." << endl;
      cout << "Done." << endl;
    }else{
      cout << "That was not an option please try again." << endl;
    }
  }
}

void DataBaseSim::printStudents(TreeNode<Student>* s){

  if(s == NULL){
    return;
  }
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

  if(f == NULL){
    return;
  }
  printFaculty(f->left);
  Faculty* faculty = f->data;
  cout << "ID: " << faculty->getID() << endl;
  cout << "Name: " << faculty->getName() << endl;
  cout << "Level: " << faculty->getLevel() << endl;
  cout << "Department: " << faculty->getDepartment() << endl;
  cout << "List of advisees ID: ";
  if(!m_students->isEmpty()){
    LinkedList<int>* advisee = faculty->getAdvisees();
    if(!advisee->isEmpty()){
      advisee->printList();
    }
  }else{
    cout << "None" << endl;
  }
  cout << endl;
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
  int id = 0;
  cout << "ID of the new student: ";
  cin >> id;
  string name = "";
  cout << "Name of the student: ";
  cin >> name;
  string level = "";
  cout << "Level of the student: ";
  cin >> level;
  string major = "";
  cout << "Major of the student: ";
  cin >> major;
  double gpa = 0.0;
  cout << "GPA of student: ";
  cin >> gpa;
  if(m_faculty->getRoot() == NULL){
    cout << "There is no faculty to set an advisor to this student." << endl;
    int advisor = 0;
    Student* s = new Student(id, name, level, major, gpa, advisor);
    m_students->insert(id, s);
    cout << "Student added to database." << endl;
    cout << endl;
    return;
  }
  cout << endl;
  cout << "Here are all the advisors: " << endl;
  TreeNode<Faculty>* root = m_faculty->getRoot();
  printFaculty(root);
  int advisor = 0;
  cout << "What is the advisors ID number: ";
  cin >> advisor;
  cout << endl;
  Faculty* f = m_faculty->search(advisor);
  while(true){
    if(f != NULL){
      f->getAdvisees()->insertFront(id);
      Student* s = new Student(id, name, level, major, gpa, advisor);
      m_students->insert(id, s);
      cout << "Student added to database." << endl;
      cout << endl;
      break;
    }else{
      cout << "Invalid advisor ID. Try again: ";
      cin >> advisor;
      cout << endl;
      f = m_faculty->search(advisor);
    }
  }
}

void DataBaseSim::deleteStudent(){
  int id = 0;
  cout << "What is the ID of the student: ";
  cin >> id;
  cout << endl;

  Student* s = m_students->search(id);
  if(s != NULL){
    if(s->getAdvisor() != 0){
      int facultyID = s->getAdvisor();
      m_students->deleteNode(id);
      Faculty* f = m_faculty->search(facultyID);
      f->getAdvisees()->remove(id);
    }
    cout << "Deleted Student." << endl;
    cout << endl;
  }else{
    cout << "This student does not exist." << endl;
    cout << endl;
  }
}

void DataBaseSim::addFaculty(){
  int id = 0;
  cout << "ID of the new faculty member: ";
  cin >> id;
  string name = "";
  cout << "Name of the faculty member: ";
  cin >> name;
  string level = "";
  cout << "Level of the faculty member: ";
  cin >> level;
  string department = "";
  cout << "Department of the faculty member: ";
  cin >> department;
  Faculty* f = new Faculty(id, name, level, department);
  m_faculty->insert(id, f);
  cout << "Faculty memeber added." << endl;
}

void DataBaseSim::deleteFaculty(){
  //could set if no other advisees available to redistribute
  int id = 0;
  cout << "What is the ID of the faculty member to be deleted: ";
  cin >> id;
  cout << endl;

  Faculty* f = m_faculty->search(id);

  if(f != NULL){
    Faculty* temp = f;
    //m_faculty->deleteNode(id);
    cout << "Deleted Faculty Member." << endl;
    if(!temp->getAdvisees()->isEmpty()){
      if(!m_faculty->isEmpty()){
        TreeNode<Faculty>* root = m_faculty->getRoot();
        printFaculty(root);
        int newID = 0;
        cout << "What faculty member would you like to transfer advisees to?(id): ";
        cin >> newID;
        cout << endl;
        Faculty* newFaculty = m_faculty->search(newID);
        while(newFaculty == NULL){
          cout << "The faculty ID you entered does not exists. Try again: " << endl;
          cin >> newID;
          newFaculty = m_faculty->search(newID);
        }
        //redistribute advisees
        ListNode<int>* curr = temp->getAdvisees()->front;
        while(curr != NULL){
          int currID = curr->data;
          Student* s = m_students->search(currID);
          s->setAdvisor(newID);
          newFaculty->getAdvisees()->insertFront(currID);
          curr = curr->next;
        }
      }
    }
  m_faculty->deleteNode(id);
  }else{
    cout << "This faculty member does not exist." << endl;
    cout << endl;
  }
}

void DataBaseSim::changeAdvisor(){
  TreeNode<Student>* root = m_students->getRoot();
  if(root == NULL){
    cout << "Students database is empty." << endl;
    return;
  }else{
    printStudents(root);
  }
  int studentID = 0;
  cout << endl;
  cout << "ID of student whose Advisor you would like to change: ";
  cin >> studentID;
  Student* s = m_students->search(studentID);
  if(s != NULL){
    cout << "Here are all the faculty members." << endl;
    int currAdvisor = s->getAdvisor();
    TreeNode<Faculty>* root = m_faculty->getRoot();
    printFaculty(root);
    int facultyID = 0;
    cout << "Which faculty member would you like to switch the student to?(ID): ";
    cin >> facultyID;
    cout << endl;

    Faculty* f = m_faculty->search(facultyID);
    if(f != NULL){
      m_students->search(studentID)->setAdvisor(facultyID);
      Faculty* oldF = m_faculty->search(currAdvisor);
      oldF->getAdvisees()->remove(facultyID);
      cout << "Changed Advisors." << endl;
    }else{
      cout << "This faculty member does not exist." << endl;
      return;
    }
  }else{
    cout << "That student does not exist." << endl;
  }
}

void DataBaseSim::removeAdvisee(){
  cout << "Here are all the faculty members: " << endl;
  TreeNode<Faculty>* root = m_faculty->getRoot();
  printFaculty(root);
  int id = 0;
  cout << "Which faculty member would you like to change advisees from?(ID): ";
  cin >> id;
  cout << endl;

  Faculty* f = m_faculty->search(id);
  if(f != NULL){
    cout << "Here are all the advisees the faculty member is responsible for: ";
    f->getAdvisees()->printList();
    cout << endl;
    int rmid = 0;
    cout << "Which advisee would your like to remove?(ID): ";
    cin >> rmid;
    cout << endl;
    f->getAdvisees()->remove(rmid);
    cout << "Removed the advisee." << endl;
    m_students->search(rmid)->setAdvisor(0);
  }else{
    cout << "This faculty member does not exist.";
  }
}

void DataBaseSim::rollBack(){

}

BST<Student>* DataBaseSim::getStudetTree(){
  return m_students;
}

BST<Faculty>* DataBaseSim::getFacultyTree(){
  return m_faculty;
}
