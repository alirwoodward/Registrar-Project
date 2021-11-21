// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Registrar.h"
#include "GenQueue.h"

// This is the header file for the simulation class
using namespace std;

class Simulation{
public:

  //most basic and essential functions for the class
  Simulation();
  ~Simulation();
  void ReadFile(string filePath);
  void RunSimulation();
  void PrintStatistics();

private:
  //all of the ADTs and Data structures used to perform the simulation
  MyList<Student>* studentsAtRegistrar;
  MyList<Student>* line;
  DoublyLinkedList<Student> *processedStudents;
  Registrar* registrarOffice;

  //function that converts strings to integer values to read from the file
  int StringToNum(string input);
  //all of the variables that will need to be calculated at the end
  float m_meanWaitTime;
  float m_medianWaitTime;
  float m_longestWaitTime;
  float m_studentsOverTenMins;
  float m_meanWindowIdle;
  float m_longestWindowIdle;
  float m_windowsIdleOverFiveMins;
  int numStudents;
  //function that helps perform all of the student metrics
  float studentWaitTimes();


  //other variables
  int clockTick;
  int lineCount;
  int time;
  int numStudentsArriving;
  int studentTimeNeeded;
};
