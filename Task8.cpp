/**
Purpose: Calculation the absolute and relative error between the numerical and analytical solution.
@author Nora Helgeland and Emilie Giltvedt Langeland
*/

#include "Task7.hpp"
#include "Task2.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

//Declaration
std::vector<double> Absolute_error(std::vector<double> u, std::vector<double> v, double n_steps, int file); 
std::vector<double> Relative_error(std::vector<double> u, std::vector<double> v, double n_steps, int file); 
double max(int i, std::vector<double> a, std::vector<double> b, std::vector<double> c); 


int main() {
    // Define number of steps
    double n_steps = 10; 

    // Define vectors for a, b and c
    std::vector<double> a(n_steps, -1); 
    std::vector<double> b(n_steps, 2);
    std::vector<double> c(n_steps, -1);

    // Use functions to find u(x) and v(x)
    std::vector<double> u = analy(n_steps, 1);
    std::vector<double> v = num(n_steps, a, b, c, 1);

    // Absolute error:
    std::vector<double> abs_error = Absolute_error(u, v, n_steps, 1);

    // Relative error
    std::vector<double> rel_error = Relative_error(u, v, n_steps, 1);


    // Absolute max error
    std::vector<double> max_rel_error(7);
    
    for (double i = 1; i <= 7; i++){
        max_rel_error[i-1] = max(i, a, b, c);
    }

    // Makes file with max error
    std::string filename = "MaxRelError.txt";
    std::ofstream ofile;
    ofile.open(filename);
    int width = 12;
    int prec  = 4;

    // Loop over steps
    for (int i = 0; i < max_rel_error.size(); i++)
    {
    ofile << std::setw(width) << std::setprecision(prec) << std::scientific << max_rel_error[i]
            << std::endl;
    }  
    ofile.close(); 

    return 0;
}

// Calculates the relative error between two vectors, and returns the maximal eliment. This doesnt work.
double max(int power, std::vector<double> a, std::vector<double> b, std::vector<double> c){
    std::vector<double> u = analy(pow(10,power), 0);
    std::vector<double> v = num(pow(10,power), a, b, c, 0);
    std::vector<double> rel_error = Relative_error(u, v, power, 0);
    return *std::max_element(rel_error.begin(), rel_error.end());
    
}

// Calculates the absolute error between two vectors with solutions v(x) and u(x)
std::vector<double> Absolute_error(std::vector<double> u, std::vector<double> v, double n_steps, int file){
    // Creates two empty vectors that wil contain the absolute errors and x-es
    std::vector<double> abs_error(n_steps);
    std::vector<double> x(n_steps-1);

    // Loop over steps and calculates the absolute error
    for(double i = 1; i < (n_steps); i++){
        x[i-1] = i*(1/n_steps);
        abs_error[i-1] = log10(abs(u[i] - v[i]));
    }

    // Creates file with absolute error
    if(file == 1){
        std::string filename = "AbsError10.txt";
        std::ofstream ofile;
        ofile.open(filename);
        int width = 12;
        int prec  = 4;

        // Loop over steps
        for (int i = 0; i < x.size(); i++)
        {
        ofile << std::setw(width) << std::setprecision(prec) << std::scientific << x[i]
                << std::setw(width) << std::setprecision(prec) << std::scientific << abs_error[i]
                << std::endl;
        }  
        ofile.close();
    }

    return abs_error;
}

// Calculates the realtive error between two vectors with solutions v(x) and u(x)
std::vector<double> Relative_error(std::vector<double> u, std::vector<double> v, double n_steps, int file){
    
    // Creates two empty vectors that wil contain the relative errors and x-es
    std::vector<double> rel_error(n_steps);
    std::vector<double> x(n_steps-1);

    // Loop over steps and calculates the relative error
    for(double i = 1; i < (n_steps); i++){
        x[i-1] = i*(1/n_steps);
        rel_error[i-1] = log10(abs((u[i]-v[i])/u[i]));
    }
    
    // Creates file with absolute error
    if(file == 1){
        std::string filename2 = "RelError10.txt";
        std::ofstream ofile2;
        ofile2.open(filename2);
        int width = 12;
        int prec  = 4;

        // Loop over steps
        for (int i = 0; i < x.size(); i++)
        {
        ofile2 << std::setw(width) << std::setprecision(prec) << std::scientific << x[i]
                << std::setw(width) << std::setprecision(prec) << std::scientific << rel_error[i]
                << std::endl;
        }  
        ofile2.close();
    }

    return rel_error;
}