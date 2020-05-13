#include <iostream>
using namespace std;

//action type object
class ActionType{
  public:
    ActionType(); //default
    ActionType(string type); //overloaded

    string getType();

  private:
    string m_type;
};
