#include <iostream>
using namespace std;

//tree node for BST
template <class T>
class TreeNode{
  public:
    TreeNode();//default
    TreeNode(int k, T* d); //overloaded
    ~TreeNode();//destructor
    //virtuall ~destructor

    int key;

    T* data;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(){
  key = 0;
  data = NULL;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(int k, T* d){
  key = k;
  data = d;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
  delete data;
  delete left;
  delete right;
}
