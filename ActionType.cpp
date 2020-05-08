#include "ActionType.h"

ActionType::ActionType(){
  m_type = "";
}
ActionType::ActionType(string type){
  m_type = type;
}

string ActionType::getType(){
  return m_type;
}
