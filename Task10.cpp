/**
Purpose: Meassuring the time difference between the two implementations of the code to solve the Poisson equation
@author Nora Helgeland and Emilie Giltvedt Langeland
*/

#include "Task7_1.hpp"
#include "Task9_1.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <chrono>


int main ()
{
    // Set number of steps
    double n_steps = 1000000; 
    // Define vectors for a, b and c
    std::vector<double> a(n_steps, -1); 
    std::vector<double> b(n_steps, 2);
    std::vector<double> c(n_steps, -1);

  // Start measuring time
  auto t1 = std::chrono::high_resolution_clock::now();

    
    std::vector<double> v = numSpecial(n_steps, a, b, c, 0);  

  // Stop measuring time
  auto t2 = std::chrono::high_resolution_clock::now();

  // Calculate the elapsed time
  // We use chrono::duration<double>::count(), which by default returns duration in seconds
  double duration_seconds = std::chrono::duration<double>(t2 - t1).count();

  // Start measuring time
  auto t1_analy = std::chrono::high_resolution_clock::now();

  std::vector<double> u = num(n_steps, 0);

    // Stop measuring time
  auto t2_analy = std::chrono::high_resolution_clock::now();

  // Calculate the elapsed time
  // We use chrono::duration<double>::count(), which by default returns duration in seconds
  double duration_seconds_analy = std::chrono::duration<double>(t2_analy - t1_analy).count();
    printf("hard time = %lf\n", duration_seconds);
    printf("easy time = %lf\n", duration_seconds_analy);

  return 0;

}
