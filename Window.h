// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar

#include <iostream>
#include "Student.h"

//header file for window class
using namespace std;

class Window{
public:
  //constructors and destructor
  Window();
  ~Window();

  //helper functions to manage window objects, get, set, check
  void updateStatus(bool status);
  void setStudent(Student* s);
  void removeStudent();
  Student* getStudent();
  bool checkStatus();
  void updateIdleTime();
  bool isWindowIdle();
  int getIdleTime();
  bool isOpen;

//member variables
private:
  int m_idleTime;
  Student* currStudent;

};
