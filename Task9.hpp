#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>


double function(double g_tilde, double v_next, double c, double b_tilde); //Declaration

double f(double x); //Declaration

std::vector<double> numSpecial(double n_steps, int file); //Declaration


std::vector<double> numSpecial(double n_steps, int file) {
    double a = -1;
    double b = 2;
    double c = -1;

    //double n_steps = 10;
    double step_size = 1/n_steps;

    std::vector<double> v(n_steps+1);
    std::vector<double> x(n_steps+1);

    std::vector<double> g_tilde(n_steps-1);
    std::vector<double> b_tilde(n_steps-1);

    g_tilde[0] = f(step_size)*(pow(step_size,2));
    b_tilde[0] = 2;

    for(double i = 1; i < (n_steps); i++){
        g_tilde[i] = f(step_size*i)*(pow(step_size,2))-(a/b_tilde[i-1])*g_tilde[i-1];
        b_tilde[i] = b - (a/b_tilde[i-1])*c;
    }

    for(double i = (n_steps-1); i >= 1; i--){

        x[i] = i*step_size;

        v[i] = function(g_tilde[i-1], v[i+1], c, b_tilde[i-1]);
    }

    v[n_steps] = 0;
    x[n_steps] = n_steps*step_size;
    v[0] = 0;
    x[0] = 0;

    if(file == 1){
        // Set a filename
        std::string filename = "output10Num.txt";

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



// double function(double g_tilde, double v_next, double c, double b_tilde){
//     //Provide definition of function here:
//     return (g_tilde - c*v_next)/b_tilde;
// }

// double f(double x){
//     //Provide definition of function here:
//     return 100*exp(-10*x); 
// }