#pragma once

#include <iostream>
#include <cmath>


#define DX 0.0001

using iter_int = unsigned long long;
using citer_int = const unsigned long long;

/* FUNCTIONS DECLARATIONS */
namespace O4
{
    double deriv(double (*f)(const double& x), const double& x, const double& dx);
}

namespace O1
{
    double deriv(double (*f)(const double& x), const double& x, const double& dx);
}

/* CLASSES */

/*
* struct which return values of calculations
*/
struct point_mass_retVals
{
    double x, v, Ek, Ep, Esum;
    void printParams();
};

/*
* class of point mass which hold movement parameters like position x, velocity v,
* kinetic energy Ek etc. in given moment.
*/
class point_mass_1D
{
    private:
        double mass, x, v, alpha, dx = DX;
        double (*V)(const double& x); //potential
                                      //
        /* FUNCTIONS */
        const double F1(const double& x, const double& v, const double& dt)
        {
            return x - this->x - dt/2*(v + this->v);
        }
        const double F2(const double& x, const double& v, const double& dt)
        {
            return v - this->v 
                   - (dt/2) * ( (-1/this->mass)*(V(x+dx)-V(x-dx))/2/dx - alpha*v )
                   - (dt/2) * ( (-1/this->mass)*(V(this->x+dx)-V(this->x-dx))/2/dx - alpha*this->v );
        }
    public:
        /* CONSTRUCTORS */
        point_mass_1D() : mass(1.), x(0.), v(0.), alpha(0.) {};
        point_mass_1D(double mass, double x, double v, double alpha) : mass(mass), x(x), v(v), alpha(alpha) {};
        point_mass_1D(double mass, double x, double v, double alpha, double (*V)(const double& x));

        /* METHODS */
        void printParams();
        void setPotential(double (*V)(const double& x) );
        void setStep(const double& dx);
        void moveTo(const double& x);
        double Vat(const double& x);
        point_mass_retVals explicitEuler(const double& delta_t);
        point_mass_retVals trapezoid_method(const double& dt, citer_int iters);
};
