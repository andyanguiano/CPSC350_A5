#include "TreeNode.h"

template <class T>
class BST{
  public:
    BST();
    ~BST();
    //virtual destructor

    void insert(int k, T* data);
    T* search(int value);
    bool deleteNode(int k);

    bool isEmpty();
    TreeNode<T>* getMin();
    TreeNode<T>* getMax();
    TreeNode<T>* getSuccessor(TreeNode<T>* d);
    void printTree(TreeNode<T> *node);
    T* traverse(TreeNode<T> *node);

    TreeNode<T>* getRoot();

  private:
    TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){
  root = NULL;
}

template <class T>
BST<T>::~BST(){

}

template <class T>
void BST<T>::printTree(TreeNode<T> *node){
  if(node == NULL){
    return;
  }
  printTree(node->left);
  cout << node->key << endl;
  printTree(node->right);
}

template <class T>
TreeNode<T>* BST<T>::getMin(){
  TreeNode<T>* curr = root;

  if(root == NULL){
    return NULL;
  }

  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}

template <class T>
TreeNode<T>* BST<T>::getMax(){
  TreeNode<T>* curr = root;

  if(root == NULL){
    return NULL;
  }

  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr;
}

template <class T>
bool BST<T>::isEmpty(){
  return(root == NULL);
}

template <class T>
void BST<T>::insert(int k, T* data){
  TreeNode<T>* node = new TreeNode<T>(k, data);

  if(search(k)){
    cout << "Value already exists" << endl;
    return;
  }

  if(isEmpty()){
    root = node;
  }else{
    TreeNode<T>* curr = root;
    TreeNode<T>* parent;

    while(true){
      parent = curr;
      if(k < curr->key){
        //go left
        curr = curr->left;
        if(curr == NULL){
          parent->left = node;
          break;
        }
      }else{
        //go right
        curr = curr->right;
        if(curr == NULL){
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
T* BST<T>::search(int value){
  if(isEmpty()){
    return NULL;
  }
  TreeNode<T>* current = root;

  while(current->key != value){
    if(value < current->key){
      current = current->left;
    }else{
      current = current->right;
    }

    if(current == NULL){
      //we did not find the value
      return NULL;
    }
  }
  return current->data;
}

template <class T>
bool BST<T>::deleteNode(int k){
  if(isEmpty()){
    return false;
  }else{
    TreeNode<T> *parent = root;
    TreeNode<T> *current = root;
    bool isLeft = true;

    while(current->key != k){
      parent = current;
      if(k < current->key){
        isLeft = true;
        current = current->left;
      }else{
        isLeft = false;
        current = current->right;
      }

      if(current == NULL){
        return false;
      }
    }
    //if we made it this far then we found the Value
    if(current->left == NULL && current->right == NULL){
      //then we have a leaf node
      if(current == root){
        root = NULL;
      }else if(isLeft){
        parent->left == NULL;
      }else{
        parent->right == NULL;
      }
    }else if(current->right == NULL){
      //no right child
      if(current == root){
        root = current->left;
      }else if(isLeft){
        parent->left = current->left;
      }else{
        parent->right = current->left;
      }
    }else if(current->left == NULL){
      //no left child
      //these branches determine positions of node to be deleted
      if(current == root){
        root = current->right;
      }else if(isLeft){
        parent->left = current->right;
      }else{
        parent->right = current->right;
      }
    }else{
      //the node to be deleted has two children
      TreeNode<T>* successor = getSuccessor(current);

      if(current == root){
        root = successor;
      }else if(isLeft){
        parent->left = successor;
      }else{
        parent->right = successor;
      }
      //connect/link successor to currents(d) left child
      successor->left = current->left;
    }
    return true;
  }
}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d){
  //the parameter d represents the node to be deleted
  TreeNode<T> *current = d->right;
  TreeNode<T> *sp = d; //successors parent
  TreeNode<T> *successor = d;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

template <class T>
T* BST<T>::traverse(TreeNode<T> *node){
  if(node == NULL){
    return NULL;
  }

  travese(node->left);
  return node->data;
  traverse(node->right);
}

template <class T>
TreeNode<T>* BST<T>::getRoot(){
  return root;
}
