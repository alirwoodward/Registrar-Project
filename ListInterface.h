// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar

#ifndef MYLIST_H //header guards
#define MYLIST_H

#include <iostream>  //import packages

using namespace std;

// List interface is a List ADT that supports the GenQueue functions in this program
template <class T>
class ListInterface{ //creating a list
public:

  //core functions
  virtual void insert(T *data) = 0;
  virtual T* remove() = 0;
  virtual T* peek() = 0;
  //aux functions
  virtual bool isFull() = 0;
  virtual bool isEmpty() = 0;
  virtual int getSize() = 0;

};


template <class T>
class MyList : public ListInterface<T>{ //creating a list
public:

  //core functions
  virtual void insert(T *data) = 0;
  virtual T* remove() = 0;
  virtual T* peek() = 0;
  //aux functions
  virtual bool isFull() = 0;
  virtual bool isEmpty() = 0;
  virtual int getSize() = 0;

};

#endif
