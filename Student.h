// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar

//header file for the student class
using namespace std;

class Student{
public:
  //constructors and destructor
  Student();
  Student(int timeNeeded, int timeArrived);
  ~Student();

  // getter and setter functions
  int getArrival();
  int getTimeNeeded();
  void setTimeNeeded(int time);
  int getWaitTime();
  void setWaitTime(int wait);
  int getExitTime();
  void setTimeHelped(int time);

  //member variables 
  int m_timeNeeded;
  int m_timeArrived;
  int m_timeHelped;
  int m_waitTime;
  int m_exitTime;
};
