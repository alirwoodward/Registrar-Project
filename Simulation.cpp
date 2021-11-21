// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar

//The simulation class is in charge of all of teh essential functionings of the program
#include "Simulation.h"

//sets all variables to zero to begin the program
//default constructor
Simulation::Simulation(){
  m_meanWaitTime = 0;
  m_medianWaitTime = 0;
  m_longestWaitTime = 0;
  m_studentsOverTenMins = 0;
  m_meanWindowIdle = 0;
  m_longestWindowIdle = 0;
  m_windowsIdleOverFiveMins = 0;
  numStudents = 0;

  studentsAtRegistrar = new GenQueue<Student>();
  line = new GenQueue<Student>();
  processedStudents = new DoublyLinkedList<Student>();
}

//destructor
Simulation::~Simulation(){
  delete line;
  delete studentsAtRegistrar;
  delete registrarOffice;
}

//gets all of the necessary information from the input file in the correct order
void Simulation::ReadFile(string filePath){

  lineCount = 0;
  Student *currStudent;

  //How line count works:
  //if line count = 0, number of windows to open
  //line count = 1, current time;
  //lineCount = 2, num of students arriving, add those students to the queue, then set lineCount back to 1 when done to restart the process.

  ifstream officeFile;
  officeFile.open(filePath);

  int numWindows = 0;
  string input = "";
  if(!officeFile.is_open()){
    cout << "Sorry, the file you have entered cannot be opened, please try again with a valid file." << endl;
    exit(1);
  }

  while(!officeFile.eof()){
    if(!officeFile.fail()){
      if(lineCount == 0){
        officeFile >> numWindows;
        //craetes an array of correct number of window objects
        registrarOffice = new Registrar(numWindows);
        ++lineCount;
    }else if (lineCount == 1){
        officeFile >> input;
        time = StringToNum(input);
        input = "";
        ++lineCount;
    }else{
        officeFile >> input;
        numStudentsArriving = StringToNum(input);
        input = "";
        for(int i = 0; i < numStudentsArriving; ++i){
          officeFile >> input;
          studentTimeNeeded = StringToNum(input);
          input = "";
          currStudent = new Student(studentTimeNeeded, time);
          ++numStudents;
          studentsAtRegistrar->insert(currStudent);
          lineCount = 1;
        }
      }
    }
  }
}

//this function then runs the actual simulation, implementing a lot of functions from the registrar class
void Simulation::RunSimulation(){

  clockTick = 0;
  //while there are people in line or at a window
  while(!registrarOffice->isOpen() || !studentsAtRegistrar->isEmpty() || !line->isEmpty()){
    Student* currentStudentInLine;
    Student* currentStudentToWindow;
    int sizeOfRegistrar = studentsAtRegistrar->getSize();
    //if the arrival time of the student matches the actual time, add the student to the line
    for(int i = 0; i < sizeOfRegistrar; ++i){
      currentStudentInLine = studentsAtRegistrar->peek();
      if(currentStudentInLine->getArrival() == clockTick){
        line->insert(currentStudentInLine);
        studentsAtRegistrar->remove();
      }
    }

    //this for loop will iterate through the current line and get people to windows if there are windows available
    for(int i = 0; i < registrarOffice->getNumWindows(); i++){
      if(registrarOffice->checkIfWindowOpen(i)){
        //sends a student from the line to an open window if the line is not empty
        if(!line->isEmpty()){
          currentStudentToWindow = line->remove();
          registrarOffice->updateWindow(i, "closed", currentStudentToWindow);
          //calculated and sets the wait time of the student
          currentStudentToWindow->setTimeHelped(clockTick);
          int waitTime = clockTick - (currentStudentToWindow->getArrival());
          currentStudentToWindow->setWaitTime(waitTime);
        }
      }
    }

    //increase time
    ++clockTick;

    //updates the idle times of open windows
    registrarOffice->updateIdleTimes();
    for(int i = 0; i < registrarOffice->getNumWindows(); ++i){
      //if the window is full check if the student is done there
      if(!registrarOffice->checkIfWindowOpen(i)){
        //if the student is done there add student to processed list and update window settings (done in registrar)
        if(registrarOffice->seeIfStudentIsDone(clockTick, i) == true){
          processedStudents->insertBack(registrarOffice->returnFinishedStudent());
        }
      }
    }
  }
}





//function to print the final statistics now that the simulation is done running
void Simulation::PrintStatistics(){

  studentWaitTimes();

  m_meanWindowIdle = registrarOffice->windowIdleTimes("mean");
  m_longestWindowIdle = registrarOffice->windowIdleTimes("longest");
  m_windowsIdleOverFiveMins = registrarOffice->windowIdleTimes("overFive");

  cout << "1. The mean wait time of students was: ";
  cout << m_meanWaitTime << endl;
  cout << "2. The median wait time of students was: ";
  cout << m_medianWaitTime << endl;
  cout << "3. The longest wait time of a student was: ";
  cout << m_longestWaitTime << endl;
  cout << "4. The number of students waiting over 10 minutes was: ";
  cout << m_studentsOverTenMins << endl;
  cout << "5. The mean window idle time was: ";
  cout << m_meanWindowIdle << endl;
  cout << "6. The longest window idle time was: ";
  cout << m_longestWindowIdle << endl;
  cout << "7. The number of windows idle for over 5 minutes was: ";
  cout << m_windowsIdleOverFiveMins << endl;
}

//function that converts strings from the file into integer values
int Simulation::StringToNum(string input){
  int number = 0;
  for(int n = 0; n < input.size(); ++n){
    number *= 10;
    number += (int(input[n]) - '0');
  }
  return number;
}

//calculates metrics for the students
float Simulation::studentWaitTimes(){

  int size = numStudents;
  int waitTimes[size];
  Student* curStu;
  for(int i = 0; i < size; ++i){
    curStu = processedStudents->peek();
    waitTimes[i] = curStu->getWaitTime();
    processedStudents->removeFront();
  }

  float totalSum = 0;
  float longest = waitTimes[0];
  float overTen = 0;

  for(int i = 0; i < size; ++i){
    totalSum += waitTimes[i];
    if(waitTimes[i] > longest){
      longest = waitTimes[i];
    }
    if(waitTimes[i] >= 10){
      ++overTen;
    }
  }
  m_meanWaitTime = totalSum/size;
  m_longestWaitTime = longest;
  m_studentsOverTenMins = overTen;

  int x = sizeof(waitTimes)/sizeof(waitTimes[0]);

  sort(waitTimes, waitTimes+x);
  int middleIndex = size%2; //rounded up
  m_medianWaitTime = waitTimes[middleIndex];

}
