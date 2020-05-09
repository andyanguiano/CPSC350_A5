#include "FileIO.h"

FileIO::FileIO(){
  m_studentFile = "studentTable.txt";
  m_facultyFile = "facultyTable.txt";
  studentTree = new BST<Student>();
  facultyTree = new BST<Faculty>();
}

FileIO::~FileIO(){
  delete studentTree;
  delete facultyTree;
}

void FileIO::traverseStudents(TreeNode<Student>* node, ofstream& o){
  if(node == NULL){
    return;
  }
  traverseStudents(node->left, o);
  Student* s = node->data;
  o << s->getID() << "|" << s->getName() << "|" << s->getLevel() << "|" << s->getMajor() << "|" << s->getGpa() << "|" << s->getAdvisor() << "|" << endl;
  traverseStudents(node->right, o);
}

void FileIO::traverseFaculty(TreeNode<Faculty>* node, ofstream &o){
  if(node == NULL){
    return;
  }
  traverseFaculty(node->left, o);
  Faculty* f = node->data;
  o << f->getID() << "|" << f->getName() << "|" << f->getLevel() << "|" << f->getDepartment() << "|" << f->adviseesForFile() << "|" << endl;
  traverseFaculty(node->right, o);
}

void FileIO::checkIfNew(){
  infs.open(m_facultyFile);
  if(!infs.is_open()){
    //file is empty
    infs.close();
    //begin simulation
    DataBaseSim* sim = new DataBaseSim(studentTree, facultyTree);
    sim->selection();
    studentTree = sim->getStudetTree();
    facultyTree = sim->getFacultyTree();
    serialize();
  }else{
    infs.close();

    deserialize();

    DataBaseSim* sim = new DataBaseSim(studentTree, facultyTree);
    sim->selection();
    studentTree = sim->getStudetTree();
    facultyTree = sim->getFacultyTree();
    serialize();
  }
}

void FileIO::serialize(){
  outfs.open(m_studentFile);
  TreeNode<Student>* rootStu = studentTree->getRoot();
  traverseStudents(rootStu, outfs);
  outfs.close();

  outfs.open(m_facultyFile);
  TreeNode<Faculty>* rootFac = facultyTree->getRoot();
  traverseFaculty(rootFac, outfs);
  outfs.close();
}

void FileIO::deserialize(){
  infs.open(m_studentFile);
  string line = "";

  while(!infs.eof()){
    getline(infs, line);

    if(!infs.fail()){
      int size = line.size();

      string idstr = "";
      string name = "";
      string level = "";
      string major = "";
      string gpastr = "";
      string advisorstr = "";
      bool idCheck = true;
      bool nameCheck = true;
      bool levelCheck = true;
      bool majorCheck = true;
      bool gpacheck = true;
      bool advisorCheck = true;

      int i = 0;

      while(true){
        if(line[i] == '|'){
          ++i;
          break;
        }else{
          idstr += line[i];
          ++i;
        }
      }

      while(true){
        if(line[i] == '|'){
          ++i;
          break;
        }else{
          name += line[i];
          ++i;
        }
      }

      while(true){
        if(line[i] == '|'){
          ++i;
          break;
        }else{
          level += line[i];
          ++i;
        }
      }

      while(true){
        if(line[i] == '|'){
          ++i;
          break;
        }else{
          major += line[i];
          ++i;
        }
      }

      while(true){
        if(line[i] == '|'){
          ++i;
          break;
        }else{
          gpastr += line[i];
          ++i;
        }
      }

      while(true){
        if(line[i] == '|'){
          ++i;
          break;
        }else{
          advisorstr += line[i];
          ++i;
        }
      }

      int id = stoi(idstr);
      double gpa = stof(gpastr);
      int advisor = stoi(advisorstr);

      Student* s = new Student(id, name, level, major, gpa, advisor);
      studentTree->insert(id, s);
    }
  }
  infs.close();


  infs.open(m_facultyFile);
  string line2 = "";

  while(!infs.eof()){
    getline(infs, line2);
    if(!infs.fail()){
      int size = line2.size();

      string idstr = "";
      string name = "";
      string level = "";
      string department = "";
      string adviseestr = "";
      LinkedList<int>* advisees = new LinkedList<int>();

      int i2 = 0;

      while(true){
        if(line2[i2] == '|'){
          ++i2;
          break;
        }else{
          idstr += line2[i2];
          ++i2;
        }
      }

      while(true){
        if(line2[i2] == '|'){
          ++i2;
          break;
        }else{
          name += line2[i2];
          ++i2;
        }
      }

      while(true){
        if(line2[i2] == '|'){
          ++i2;
          break;
        }else{
          level += line2[i2];
          ++i2;
        }
      }

      while(true){
        if(line2[i2] == '|'){
          ++i2;
          break;
        }else{
          department += line2[i2];
          ++i2;
        }
      }
      //SAVES BUT DOES NOT READ IT RIGHT
      if(line2[i2] == 'e'){
        cout << "HERE" << endl;
        int id = stoi(idstr);
        Faculty* f = new Faculty(id, name, level, department);
        facultyTree->insert(id, f);
      }else{
        while(true){
          cout << "HERE2" << endl;
          if(line2[i2] == '|'){
            ++i2;
            break;
          }else if(line2[i2] =! ' '){
            cout << "ADVISEE: " << adviseestr << endl;
            int advisee = stoi(adviseestr);
            advisees->insertFront(advisee);
            adviseestr = "";
            ++i2;
          }else{
            adviseestr += line2[i2];
            ++i2;
          }
        }
        int id = stoi(idstr);
        Faculty* f = new Faculty(id, name, level, department);
        f->setAdvisees(advisees);
        facultyTree->insert(id, f);
      }
    }
  }
  infs.close();
}
