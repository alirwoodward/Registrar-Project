// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar

//Student class that is in charge of holding information for student objects
#include "Student.h"

//default constructor
Student::Student(){
  m_timeNeeded = 0;
  m_timeArrived = 0;
  m_waitTime = 0;
  m_exitTime = 0;
}

//overloaded constructor
Student::Student(int timeNeeded, int timeArrived){
  m_timeNeeded = timeNeeded;
  m_timeArrived = timeArrived;
}

//destructor
Student::~Student(){

}

//returns the time the student arrived in line
int Student::getArrival(){
  return m_timeArrived;
}

//returns the amount of time the student needs assistance
int Student::getTimeNeeded(){
  return m_timeNeeded;
}

//sets the amount of time the student needs assistance
void Student::setTimeNeeded(int time){
  m_timeNeeded = time;
}

//sets the amount of time that the student waited
void Student::setWaitTime(int wait){
  m_waitTime = wait;
}

//returns the student wait time
int Student::getWaitTime(){
  return m_waitTime;
}

//returns the time that the student exited the window
int Student::getExitTime(){
  return m_exitTime;
}


//sets the time that the student was helped at, helpful for calculating time waited
void Student::setTimeHelped(int time){
  m_timeHelped = time;
  m_exitTime = m_timeHelped + m_timeNeeded;
  int wait = m_timeHelped - m_timeArrived;
  setWaitTime(wait);
}
