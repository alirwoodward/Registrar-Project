// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar
#include "Window.h"

//default constructor
Window::Window(){
  m_idleTime = 0;
  isOpen = true;
  currStudent = NULL;
}

//destructor
Window::~Window(){
 delete currStudent;
}

//updates the status (open or full) of a window
void Window::updateStatus(bool status){
  isOpen = status;
  if(isOpen == false){
  }
}

//checks to see if a window is full or not
bool Window::checkStatus(){
  return isOpen;
}

//sets the student the just came to the window
void Window::setStudent(Student* s){
  currStudent = s;
}

//removes the student who just left the window
void Window::removeStudent(){
  currStudent = NULL;
}

//gets the student currently at the window
Student* Window::getStudent(){
  return currStudent;
}

//adds to the idle time if the window is sitting open
void Window::updateIdleTime(){
  m_idleTime++;
}

//checks to see if the window is idle
bool Window::isWindowIdle(){
  return (!isOpen);
}

//gets the total idle time of the window 
int Window::getIdleTime(){
  return m_idleTime;
}
