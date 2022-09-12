/**
Purpose: Returns a vector which is the the analytcal solution to the Poisson equation.
@author Nora Helgeland and Emilie Giltvedt Langeland
*/

#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

//Declarations
double function1(double x); 
std::vector<double> analy(double n_steps, int file); 

// Main function that returns a vector with u(x) values for n_steps, 
// and creates a file with the values.
std::vector<double> analy(double n_steps, int file) {

    // Define step size
    double step_size = 1/n_steps;

    // Create a vector<double> with the x-es
    std::vector<double> x(n_steps + 1);
    
    // Create a vector<double> with u(x)-es
    std::vector<double> u(n_steps + 1);

    // Loop over every step (except first and last) and calculate the u(x)
    for (size_t i = 0; i < x.size(); i++){
     x[i] = step_size*i;
     u[i] = function1(step_size*i);
     }

    // Define the boundary points 
     u[0] = 0;
     u[n_steps] = 0;

    // If input equals one, a file is created.
    if(file == 1){
        // Set a filename
        std::string filename = "output1000Rel.txt";

        // Create and open the output file. Or, technically, create 
        // an "output file stream" (type std::ofstream) and connect 
        // it to our filename.
        std::ofstream ofile;
        ofile.open(filename);

        int width = 12;
        int prec  = 4;

        // Loop over steps
        for (int i = 0; i < x.size(); i++)
        {
        // Write a line with the current x and y values (nicely formatted) to file
        ofile << std::setw(width) << std::setprecision(prec) << std::scientific << x[i]
                << std::setw(width) << std::setprecision(prec) << std::scientific << u[i]
                << std::endl;
        }  
        ofile.close();
    }

    return u;

    }

// Return the analytical solution u(x)
double function1(double x){
    //Provide definition of function here:
    return 1 - (1-exp(-10))*x - exp(-10*x);
}
