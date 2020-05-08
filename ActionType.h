#include <iostream>
using namespace std;

class ActionType{
  public:
    ActionType();
    ActionType(string type);

    string getType();

  private:
    string m_type;
};
