#ifndef FACULTY_H
#define FACULTY_H
#include "LinkedList.h"

//faculty object
class Faculty{
  public:
    Faculty();//default
    Faculty(int id, string name, string level, string department);//overlaoded
    ~Faculty();//destructor

    //getters setters
    void setID(int id);
    int getID();

    void setName(string name);
    string getName();

    void setLevel(string level);
    string getLevel();

    void setDepartment(string department);
    string getDepartment();

    void setAdvisees(LinkedList<int>* advisees);
    LinkedList<int>* getAdvisees();

    string adviseesForFile();//returns a string to print to the file to save

    int comapareTo(Faculty *f);//compare faculty members

  private:
    int m_id;
    string m_name;
    string m_level;
    string m_department;
    LinkedList<int>* m_advisees;
};

#endif
