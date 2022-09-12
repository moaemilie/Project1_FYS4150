#include "Task7.hpp"
#include "Task9.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>



#include <chrono>

int main ()
{

    double n_steps = 1000000; 
    std::vector<double> a(n_steps, -1); //Finne ut av senere
    std::vector<double> b(n_steps, 2);
    std::vector<double> c(n_steps, -1);

  // Start measuring time
  auto t1 = std::chrono::high_resolution_clock::now();

    
    std::vector<double> v = num(n_steps, a, b, c, 0);  

  // Stop measuring time
  auto t2 = std::chrono::high_resolution_clock::now();

  // Calculate the elapsed time
  // We use chrono::duration<double>::count(), which by default returns duration in seconds
  double duration_seconds = std::chrono::duration<double>(t2 - t1).count();

  // ...

  // Start measuring time
  auto t1_anal = std::chrono::high_resolution_clock::now();

  std::vector<double> u = numSpecial(n_steps, 0);

    // Stop measuring time
  auto t2_anal = std::chrono::high_resolution_clock::now();

  // Calculate the elapsed time
  // We use chrono::duration<double>::count(), which by default returns duration in seconds
  double duration_seconds_anal = std::chrono::duration<double>(t2_anal - t1_anal).count();
    printf("hard time = %lf\n", duration_seconds);
    printf("easy time = %lf\n", duration_seconds_anal);

  return 0;

}
