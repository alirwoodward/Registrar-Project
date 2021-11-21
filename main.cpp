// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350 Section 03
// Assignment	5- Registrar


#include "Simulation.h"

//main method only calls commands for the simulation
int main(int argc, char** argv){
  Simulation s;
  string filePath = argv[1];

  s.ReadFile(filePath);
  s.RunSimulation();
  s.PrintStatistics();

  return 0;
}
