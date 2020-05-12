#include "ListNode.h"

template <class T>
class LinkedList{
  public:
    LinkedList();
    ~LinkedList();

    void insertFront(T data);
    T removeFront();
    int search(T val); //return position of ListNode
    T remove(T val);
    bool searchBool(T val);
    void removeAtPos(int pos);

    unsigned int getSize();
    bool isEmpty();
    void printList();
    ListNode<T>* front;

    unsigned int size;
};

template <class T>
LinkedList<T>::LinkedList(){
  size = 0;
  front = NULL;
}

template <class T>
LinkedList<T>::~LinkedList(){
  front = NULL;
  delete front;
}

template <class T>
unsigned int LinkedList<T>::getSize(){
  return size;
}

template <class T>
bool LinkedList<T>::isEmpty(){
  return (size == 0);
}

template <class T>
void LinkedList<T>::printList(){
  ListNode<T> *current = front;

  while(current != NULL){
    cout << current->data << endl;
    current = current->next;//listnode
  }
  cout << endl;
}

template <class T>
void LinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  node->next = front;
  front = node;
  size++;
}

template <class T>
T LinkedList<T>::removeFront(){
  if(!isEmpty()){
    T* temp = front->data;
    ListNode<T>* ft = front;
    front = front->next;
    ft->next = NULL;
    delete ft;
    size--;

    return temp;
  }
}

template <class T>
int LinkedList<T>::search(T val){
  int pos = -1;
  ListNode<T> *curr = front;
  //loop and attempt to find the value
  while(curr != NULL){
    ++pos;
    if(curr->data == val){
      //we found it
      break;
    }else{
      //we didnt continue iterating
      curr = curr->next;
    }
  }
    if(curr == NULL){
      //didnt find it
      pos = -1;
    }
    return pos;
}

template <class T>
bool LinkedList<T>::searchBool(T val){
  bool myBool = false;
  ListNode<T> *curr = front;
  while(curr != NULL){
    if(curr->data == val){
      myBool = true;
      break;
    }
  }
  return myBool;
}

template <class T>
T LinkedList<T>::remove(T val){
  //error to make sure pos does not exceed size of listnode
  ListNode<T> *curr;
  ListNode<T> *prev = front;

  while(curr != NULL){
    //loop until I find the position
    prev = curr;
    curr = curr->next;
    if(val == curr->data){
      break;
    }
  }
  //continue with the delete process
  prev->next = curr->next;
  curr->next = NULL;
  T temp = curr->data;
  delete curr;
  size--;

  return temp;
}

template <class T>
void LinkedList<T>::removeAtPos(int pos){
  int index = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;
  while(index != pos){
    prev = curr;
    curr = curr->next;
    index += 1;
  }
  if(isEmpty()){
    return;
  }else if(size == 1){
    curr->next = NULL;
  }else if(pos == 0){
    front = front->next;
    curr->next = NULL;
  }else if(pos == size - 1){
    prev->next = NULL;
  }else{
    prev->next = curr->next;
    curr->next = NULL;
  }

  delete curr;
  size -= 1;
}
