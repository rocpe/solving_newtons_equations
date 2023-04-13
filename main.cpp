/*
 *  github.com/rocpe
 *  Program which calculates parameters of 1D movement in potential V(x).
 *  Outcome of calculations is saved in mass[NUMBER]_file.csv . Compile with "make"
 *
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include "point_mass_1D.hpp"

using namespace std; 

//typedef unsigned long long iter_int;
using iter_int = unsigned long long;
using citer_int = const unsigned long long;

#define TIME 1000
#define DT 0.01
citer_int N = TIME/DT;
#define ITERS 5


//used function, tweak V_pot as you wish
double V_pot(const double& x);
void save(point_mass_retVals* toSave, const size_t N, char* fileName);

/* MAIN */
int main()
{
    /* POINT MASSED AND ARRAYS OF STRUCTS WHICH HOLD PARAMETER OF MOVEMENT */
    /*
     * You can change the point mass starting parameters (like x0, v0, mass etc).
     * alpha is resistance coefficient.
     *
     */
    //arrays of structs which hold parameter of movement
    point_mass_retVals* mass1_data = new point_mass_retVals[N];

    //point mass of mass=1, x0=2.8, v0=0., alpha=0, V=V_pot
    point_mass_1D mass1(1., 2.8, 0., 0., V_pot);


    //arrays of structs which hold parameter of movement
    point_mass_retVals* mass2_data = new point_mass_retVals[N];

    //point mass of mass=1, x0=2.8, v0=0., alpha=5, V=V_pot
    point_mass_1D mass2(1., 2.8, 0., 5., V_pot);


    //arrays of structs which hold parameter of movement
    point_mass_retVals* mass3_data = new point_mass_retVals[N];

    //point mass of mass=1, x0=2.8, v0=0., alpha=0.5, V=V_pot
    point_mass_1D mass3(1., 2.8, 0., 0.5, V_pot);



    /* CALCULATIONS */
    //iteration for t=(0,TIME) with dt = 0.01
    for(iter_int i = 0; i < N; i++)
    {
        mass1_data[i] = mass1.explicitEuler(DT);
        mass2_data[i] = mass2.explicitEuler(DT);
        mass3_data[i] = mass3.trapezoid_method(DT, ITERS);
    }



    /* SAVING ARRAYS OF DATA TO FILES */
    char mass1_file[] = "mass1_file.csv";
    save(mass1_data, N, mass1_file);

    char mass2_file[] = "mass2_file.csv";
    save(mass2_data, N, mass2_file);

    char mass3_file[] = "mass3_file.csv";
    save(mass3_data, N, mass3_file);



    /* CLEANING MEMORY */
    delete[] mass1_data;
    delete[] mass2_data;
    delete[] mass3_data;
}

/* FUNCTIONS */
double V_pot(const double& x)
{
    /*
     *  HERE YOU CAN PUT YOUR FUNCTION OF POTENTIAL!!!
     */
    return -exp( -pow(x, 2.) ) - 1.2*exp( -pow((x-2), 2.) );
}

void save(point_mass_retVals* toSave, const size_t N, char* fileName)
{
    std::ofstream FILE (fileName);
    if(FILE.is_open())
    {
        FILE << "x;v;Ek;Ep;Esum #mass is 1kg\n";
        for(iter_int i = 0; i < N; i++)
            FILE << toSave[i].x << ";" << toSave[i].v << ";" << 
                   toSave[i].Ek << ";" << toSave[i].Ep << ";" <<
                   toSave[i].Esum  << "\n";
    }
}
