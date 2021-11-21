// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar

//This class is in charge of the overall functioning of the Registrar's office
#include "Registrar.h"

//default constructor, never used in this program
Registrar::Registrar(){
  m_office = new Window*[120];
  m_numWindows = 120;
}

//overloaded constructor
//creates array of windows for the correct number of windows being tested
//sets m_numWindows to the correct number
Registrar::Registrar(int numWindows){
  m_office = new Window*[numWindows];
  for(int i = 0; i < numWindows; ++i){
    m_office[i] = new Window();
  }
  m_numWindows = numWindows;
}

//destructor
Registrar::~Registrar(){
  delete[] m_office;
  delete finishedStudent;
}

//returns number of windows
int Registrar::getNumWindows(){
  return m_numWindows;
}

//checks to see if a window is open or full and returns a boolean
bool Registrar::checkIfWindowOpen(int window){
  if(m_office[window]->checkStatus() == true){
    return true;
  }else{
    return false;
  }
}

//updates a windows status using the window ID, the status (open or full), and the student currently at the window
//only actually used to set a window to being full and insert the student at the correct window
void Registrar::updateWindow(int windowNumber, string status, Student* studentAtWindow){
  if(status == "closed"){
    m_office[windowNumber]->updateStatus(false);
  }else{
    m_office[windowNumber]->updateStatus(true);
  }
  m_office[windowNumber]->setStudent(studentAtWindow);
}

//returns a boolean specifying whether or not the entire office is empty
//helpful for ending the while loop in simulation once everyone is gone
bool Registrar::isOpen(){
  int countClosed = 0;
  for(int i = 0; i < m_numWindows; ++i){
    if(!m_office[i]->checkStatus()){
      ++countClosed;
    }
  }
  if(countClosed == 0){
    return true;
  }else{
    return false;
  }
}

//updates idle times by figuring out whether each window is open or full
void Registrar::updateIdleTimes(){
  //adds 1 to idle time of every open window
  for(int i = 0; i < m_numWindows; ++i){
    if(m_office[i]->checkStatus() == true){
      m_office[i]->updateIdleTime();
    }
  }
}

//checks if a student is done at the window but seeing if their exit time matches the actual time
// if student is done, takes the needed actions
// assigns that student as finished student
// removes student from window and updates the status of the window to being empty
bool Registrar::seeIfStudentIsDone(int time, int wind){
  if((m_office[wind]->getStudent())->getExitTime() == time){
    finishedStudent = m_office[wind]->getStudent();
    m_office[wind]->removeStudent();
    m_office[wind]->updateStatus(true);
    return true;
  }else{
    return false;
  }
}

// returns the student that was just removed from a window to be put into the processed students array in the simulation class
Student* Registrar::returnFinishedStudent(){
  return finishedStudent;
}

//window idle times performs the calculations that are prouced at the very end of the program
//calculates the mean idle time, longest idle time, and how many windows had an idle time over 5
float Registrar::windowIdleTimes(string identifier){
  float idleTimes[m_numWindows];
  for(int i = 0; i < m_numWindows; ++i){
    idleTimes[i] = m_office[i]->getIdleTime();
  }

  if(identifier == "mean"){
    float totalSum = 0;
    for(int i = 0; i < m_numWindows; ++i){
      totalSum += idleTimes[i];
    }
    return totalSum/m_numWindows;
  }

  if(identifier == "longest"){
    float longest = 0;
    for(int i = 0; i < m_numWindows; ++i){
      if(idleTimes[i] > longest){
        longest = idleTimes[i];
      }
    }
    return longest;
  }

  if(identifier == "overFive"){
    float overFive = 0;
    for(int i = 0; i < m_numWindows; ++i){
      if(idleTimes[i] >= 5){
        ++overFive;
      }
    }
    return overFive;
  }
}
