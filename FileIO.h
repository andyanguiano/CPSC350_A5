#include "DataBaseSim.h"
#include <fstream>

using namespace std;

//serialize and deserialize
class FileIO{
  public:
    FileIO();//constructor
    ~FileIO();//destructor

    void traverseStudents(TreeNode<Student>* node, ofstream &o); //print student file
    void traverseFaculty(TreeNode<Faculty>* node, ofstream &o); //print faculty file
    void checkIfNew();//see if new database
    void serialize();
    void deserialize();//reads files

  private:
    ifstream infs;
    ofstream outfs;

    string m_studentFile;
    string m_facultyFile;
    BST<Student>* studentTree;
    BST<Faculty>* facultyTree;

};
