// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar

//Header file for the Registrar class
#include "Window.h"
using namespace std;

 class Registrar{
 public:
   Registrar();
   Registrar(int numWindows);
   ~Registrar();


   //functions that help Registrar function, all called from simulate
   int getNumWindows();
   bool checkIfWindowOpen(int window);
   void updateWindow(int windowNumber, string status, Student* studentAtWindow);
   void updateIdleTimes();
   bool isOpen();
   bool seeIfStudentIsDone(int time, int wind);
   Student* returnFinishedStudent();
   float windowIdleTimes(string identifier);
   Student* finishedStudent;

//m_office is the array of window pointers to keep track of the windows as objects
 private:
   Window **m_office;
   int m_numWindows;
 };
