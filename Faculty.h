#ifndef FACULTY_H
#define FACULTY_H
#include "LinkedList.h"

class Faculty{
  public:
    Faculty();
    Faculty(int id, string name, string level, string department);
    ~Faculty();

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

    int comapareTo(Faculty *f);

  private:
    int m_id;
    string m_name;
    string m_level;
    string m_department;
    LinkedList<int>* m_advisees;
};

#endif
