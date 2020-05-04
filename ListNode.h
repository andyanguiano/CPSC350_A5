#include <iostream>
using namespace std;

template <class T>
class ListNode{
  public:
    ListNode();
    ListNode(T d);
    ~ListNode();

    T data;
    ListNode<T>* next;
};

template <class T>
ListNode<T>::ListNode(){
  data = NULL;
  next = NULL;
}

template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
  delete next;
}
