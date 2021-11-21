// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar

#ifndef GENQUEUE_H
#define GENQUEUE_H
# include <iostream>
#include <exception>
#include "LinkedList.h"
#include "ListInterface.h"

//template class version of the GenQueue that we created in class
//Implements a linked list
using namespace std;

template <class type>
class GenQueue : public MyList<type>{
  public:
    GenQueue(); //constructur
    //GenQueue(unsigned int maxSize);
    ~GenQueue(); //destructor

    //core function
    void insert(type* data); // aka enqueue()
    type* remove(); // aka dequeue()

    //aux functions
    type* peek();
    int getSize();
    bool isFull();
    bool isEmpty();
    void printArray();

  private:
    unsigned int mSize;
    int front;
    int rear;
    int numElements;
    //type *myQueue;
    DoublyLinkedList<type> *myQueue;

};

template <class type>
GenQueue<type>::GenQueue(){
  mSize = 128; //default size
  myQueue = new DoublyLinkedList<type>;
  //myQueue = new type[mSize];
  front = 0;
  rear = 0;
  numElements = 0;
}

template <class type>
GenQueue<type>::~GenQueue(){
  delete myQueue;
}

template <class type>
void GenQueue<type>::insert(type* data){
  if(isFull()){
    throw runtime_error("queue is full!!!");

  }

  myQueue->insertBack(data);
  ++rear;
  ++numElements;

}

template <class type>
type* GenQueue<type>::remove(){
  if(isEmpty()){
    throw runtime_error("queue is empty!!!");
  }
  type* c = myQueue->removeFront();
  ++front;
  --numElements;
  return c;
}

template <class type>
type* GenQueue<type>::peek(){
  if(isEmpty()){
    throw runtime_error("queue is empty!!!");
  }
  return myQueue->peek();
}

template <class type>
bool GenQueue<type>::isEmpty(){
  return (numElements == 0);
}

template <class T>
bool GenQueue<T>::isFull(){
  return (numElements == mSize);
}

template <class type>
int GenQueue<type>::getSize(){
  return numElements;
}

#endif
