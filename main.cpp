#include "BST.h"

int main(int argc, char **argv) {

  BST<int>* myBST = new BST<int>();

  myBST->insert(1);
  myBST->insert(5);
  myBST->insert(30);
  myBST->insert(2);
  myBST->insert(28);

  cout << myBST->search(6) << endl;
  myBST->deleteNode(1);
  //myBST->deleteNode(30);

  cout << myBST->getMin()->key << endl;
  cout << myBST->getMax()->key << endl;

  return 0;
}
