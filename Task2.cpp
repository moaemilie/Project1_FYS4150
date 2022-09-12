#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


double f(double x); //Declaration

int main() {

    double n_steps = 10;
    double step_size = 1/n_steps;

    // Create a vector<double> of length 11 with x-es
    std::vector<double> x(n_steps + 1);
    
    // Create a vector<double> of length 11 with u(x)-es
    std::vector<double> u(n_steps + 1);

    for (size_t i = 0; i < x.size(); i++){
     x[i] = step_size*i;
     u[i] = f(step_size*i);
     }

     u[0] = 0;
     u[n_steps] = 0;

     // Set a filename
    std::string filename = "output10Rel.txt";

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

    return 0;

    }

double f(double x){
    //Provide definition of function here:
    return 1 - (1-exp(-10))*x - exp(-10*x);
}
