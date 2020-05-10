//Andy Anguiano
//2316199
//aanguiano@champman.edu
//CPSC 350-02
//Assignemnt 5

#include <iostream>

using namespace std;

//templates allow to use of any data type
template <class T>
//reuasabel code for stack of any data type
class GenStack{
  public:
    GenStack();//default constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); // destructor

    //core functions
    void push(T* data); // insert an item
    T* pop(); //remove

    //aux/helper functions
    T peek(); // aka top
    bool isEmpty();//checks if stack is empty
    bool isFull();//checks is stack is full
    int getSize();//returns size of stack
    GenStack *allocateMemory();//when a stack is full, returns a larger stack

    int top;//holds the value for the top of the stack
    int mSize;//holds the value of the size

    T** myArray; //memory address of the fisrt block

};


//default constructor
template <class T>
GenStack<T>::GenStack(){
  myArray = new T*[500];
  for(int i = 0; i < 500; ++i){
    myArray[i] = new T();
  }
  mSize = 500;
  top = -1;
}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T*[maxSize];
  for(int i = 0; i < maxSize; ++i){
    myArray[i] = new T();
  }
  mSize = maxSize;
  top = -1;
}
//destructor
template <class T>
GenStack<T>::~GenStack(){
  delete myArray;
}
//changes top
template <class T>
void GenStack<T>::push(T* data){
  myArray[++top] = data;
}

template <class T>
T* GenStack<T>::pop(){
  if(isEmpty()){
    return NULL;
  }else{
    return myArray[top--];
  }
}

template <class T>
T GenStack<T>::peek(){
  return myArray[top];
}
template <class T>
bool GenStack<T>::isFull(){
  cout << "SIZE: " << mSize << endl;
  return (top == mSize - 1);
}
template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

template <class T>
int GenStack<T>::getSize(){
  return mSize;
}
