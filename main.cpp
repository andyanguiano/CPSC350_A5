#include "DataBaseSim.h"

int main(int argc, char **argv) {
  BST<Student>* students = new BST<Student>();
  BST<Faculty>* faculty = new BST<Faculty>();

  DataBaseSim* sim = new DataBaseSim(students, faculty);

  sim->selection();
  return 0;
}
