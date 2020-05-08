#include "DataBaseSim.h"
#include <fstream>

class FileIO{
  public:
    FileIO();
    ~FileIO();

    void traverseStudents(TreeNode<Student>* node, ofstream &o);
    void traverseFaculty(TreeNode<Faculty>* node, ofstream &o);
    void checkIfNew();
    void serialize();
    void deserialize();

  private:
    ifstream infs;
    ofstream outfs;

    string m_studentFile;
    string m_facultyFile;
    BST<Student>* studentTree;
    BST<Faculty>* facultyTree;

};
