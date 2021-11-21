// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar

//LinkedList.h is a file that contains all working functions of a linked list
//contains class ListNode to facilitate list nodes in the linked list and contains class DoublyLinkedList to facilitate linked list

//DoublylinkedList class contains methods: insertFront, insertBack, removeFront, removeBack, removeNode, find, isEmpty, getSize, and peek.

#ifndef LINKDELIST_H
#define LINKEDLIST_H

#include <iostream>
#include <exception>
using namespace std;

template <class type>
class ListNode{
public:
  ListNode();
  ListNode(type* d);
  ~ListNode();
  type* data;
  ListNode *next;
  ListNode *prev;
};

//implementation
//**should be in a .cpp unless you are working with a template class**

template <class type>
ListNode<type>::ListNode(){}

template <class type>
ListNode<type>::ListNode(type* d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <class type>
ListNode<type>::~ListNode(){
  //guess what, build some character
  //research this


  next = NULL; //is this all we need in the destructor???
}

template <class type>
class DoublyLinkedList{
private:
  ListNode<type> *front;
  ListNode<type> *back;
  int size;
public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(type* d);
  void insertBack(type* d);
  type* removeFront();
  type* removeBack();
  type removeNode(type value);
  int find(type value);
  bool isEmpty();
  int getSize();
  type* peek();
};


template <class type>
DoublyLinkedList<type>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template <class type>
DoublyLinkedList<type>::~DoublyLinkedList(){
  //build some character
  ListNode<type> *curr = front;
  //while loop that goes through and deletes pointers throughought the linked list
  //no idea if this works
  while( curr != 0 ) {
      ListNode<type> *next = curr->next;
      delete curr;
      curr = next;
  }
  front = 0;
  delete front;
  delete back;
}

template <class type>
void DoublyLinkedList<type>::insertFront(type* d){
  ListNode<type> *node = new ListNode<type>(d);

  if(isEmpty()){
    back = node;
  }else{
    node->next = front;
    front->prev = node;
  }
  front = node;
  ++size;
}

template <class type>
void DoublyLinkedList<type>::insertBack(type* d){
  ListNode<type> *node = new ListNode<type>(d);

  if(isEmpty()){
    front = node;
  }else{
    node->prev = back;
    back->next = node;
  }
  back = node;
  ++size;
}


template <class type>
type* DoublyLinkedList<type>::removeFront(){
  if(isEmpty()){
    throw runtime_error("list is empty");
  }

  ListNode<type> *temp = front;

  if(front->next == NULL){
    back = NULL;
  }else{
    //more than one node in list
    front -> next-> prev = NULL;
  }
  front = front ->next;
  type* data = temp->data;
  --size;
  delete temp;
  return data;
}

template <class type>
type* DoublyLinkedList<type>::removeBack(){
  if(isEmpty()){
    throw runtime_error("list is empty");
  }
  ListNode<type> *temp = back;
  if(back->prev == NULL){
    front = NULL;
  }else{
    back ->prev->next = NULL;
  }
  back = back ->prev;
  temp->prev = NULL;
  type* data = temp->data;
  --size;
  delete temp;
  return data;
}

template <class type>
int DoublyLinkedList<type>::find(type value){
  int position = -1;
  ListNode<type> *curr = front;
  while(curr != NULL){
    ++position;
    if(curr ->data == value){
      break;
    }
    curr = curr->next;
  }
  if(curr == NULL){
    position = -1;
  }
  return position;
}

template <class type>
bool DoublyLinkedList<type>::isEmpty(){
  return(size == 0);
}

template <class type>
type DoublyLinkedList<type>::removeNode(type value){
  if(isEmpty()){
    throw runtime_error("list is empty");
  }
  ListNode<type> *curr = front;
  while(curr->data != value){
    curr = curr -> next;

    if(curr == NULL){
      return -1;
    }
  }
  if(curr != front && curr != back){
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }

  if(curr == front){
    front = curr->next;
    front -> prev = NULL;
  }
  if(curr == back){
    back = curr ->prev;
    back -> next = NULL;
  }

  curr->next = NULL;
  curr->prev = NULL;
  type data = curr->data;
  --size;
  delete curr;
  return data;
}

template <class type>
type* DoublyLinkedList<type>::peek(){
  return front->data;
}

template <class type>
int DoublyLinkedList<type>::getSize(){
  return size;
}

#endif
