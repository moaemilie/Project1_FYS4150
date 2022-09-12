/**
Purpose: Returns a vector which is the the numerical solution to the Poisson equation.
@author Nora Helgeland and Emilie Giltvedt Langeland
*/

#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

//Declaration
double function(double g_tilde, double v_next, double c, double b_tilde); 
double f(double x); 
std::vector<double> num(double n_steps, int file); 

// Main function that returns a vector with v(x) values for n_steps, 
// and creates a file with the values.
std::vector<double> num(double n_steps, int file) {
    // Defines the a, b, c that is used in the formula.
    double a = -1;
    double b = 2;
    double c = -1;

    // Define the step size
    double step_size = 1/n_steps;

    // Create empty vectors that wil hold the x-es and the v(x)-es
    std::vector<double> v(n_steps+1);
    std::vector<double> x(n_steps+1);

    // Create empty vectors that wil hold the g_tilde-es and the b_tilde-es
    std::vector<double> g_tilde(n_steps-1);
    std::vector<double> b_tilde(n_steps-1);

    // Calculate the first values of b_tilde and g_tilde
    g_tilde[0] = f(step_size)*(pow(step_size,2));
    b_tilde[0] = 2;

    // Loop over every step to find the corrresponding g_tilde and b_tilde
    for(double i = 1; i < (n_steps); i++){
        g_tilde[i] = f(step_size*i)*(pow(step_size,2))-(a/b_tilde[i-1])*g_tilde[i-1];
        b_tilde[i] = b - (a/b_tilde[i-1])*c;
    }

    // Define boundary points
    v[n_steps] = 0;
    x[n_steps] = n_steps*step_size;
    v[0] = 0;
    x[0] = 0;

    // Loop over every step to calculate v(x)
    for(double i = (n_steps-1); i >= 1; i--){

        x[i] = i*step_size;

        v[i] = function(g_tilde[i-1], v[i+1], c, b_tilde[i-1]);
    }
    // If input equals one, a file is created.
    if(file == 1){
        // Set a filename
        std::string filename = "output1000Num.txt";

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
                << std::setw(width) << std::setprecision(prec) << std::scientific << v[i]
                << std::endl;
        }  
        ofile.close();

    }


    return v;

}

// Returns v(x)
 double function(double g_tilde, double v_next, double c, double b_tilde){
     //Provide definition of function here:
     return (g_tilde + v_next)/b_tilde;
    }

// Returns f(x)
 double f(double x){
     //Provide definition of function here:
     return 100*exp(-10*x); 
 }