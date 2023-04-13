#include "point_mass_1D.hpp"

/* FUNCTIONS */
namespace O4
{
    //derivative of error O(4)
    double deriv(double (*f)(const double& x), const double& x, const double& dx)
    {
        return (f(x-2*dx) - 8*f(x-dx) + 8*f(x+dx) - f(x+2*dx))/(12*dx);
    }
}
namespace O1
{
    //derivative of error O(1)
    double deriv(double (*f)(const double& x), const double& x, const double& dx)
    {
        return (f(x+dx) - f(x))/(dx);
    }
}

/* CONSTRUCTORS */
point_mass_1D::point_mass_1D(double mass, double x, double v, double alpha,
        double (*V)(const double& x) ) : mass(mass), x(x), v(v), alpha(alpha), V(V) {};

/* METHODS */
void point_mass_retVals::printParams()
{
    std::cout << x << ";" << v << ";" << Ek << ";" << Ep << ";" << Esum << std::endl;
}


void point_mass_1D::printParams()
{
    std::cout << "Mass: " << mass << "\nx: " << x
        << "\nv: "  << v << "\nAlpha: " << alpha <<  std::endl;
}

void point_mass_1D::setPotential(double (*V)(const double& x) ){ this->V = V; }

void point_mass_1D::setStep(const double& dx){ this->dx = dx; }

void point_mass_1D::moveTo(const double& x){ this->x = x; }

double point_mass_1D::Vat(const double& x) { return this->V(x); }

//explicit Euler method. It changes parameter of class
point_mass_retVals point_mass_1D::explicitEuler(const double& delta_t)
{
    //struct which holds return values of the calculations
    point_mass_retVals retVals;
    
    //explicit Euler equations
    retVals.x = this->x + this->v*delta_t;

    double dVx = O4::deriv(this->V, this->x, this->dx);
    retVals.v = this->v - (1/this->mass)*dVx*delta_t - this->alpha*this->v*delta_t;

    retVals.Ek = this->mass * retVals.v*retVals.v  / 2;
    retVals.Ep = this->mass * this->V(retVals.x);
    retVals.Esum = retVals.Ek + retVals.Ep;

    //remember new values
    this->x = retVals.x;
    this->v = retVals.v;

    return retVals;
}

//trapezoid method. It changes parameter of class
point_mass_retVals point_mass_1D::trapezoid_method(const double& dt, citer_int iters)
{
    //struct which holds return values of the calculations
    point_mass_retVals retVals;

    double x_iter = this->x, v_iter = this->v;
    for(iter_int i = 0; i < iters; i++)
    {
        //solving "iters" times system of two equations. For more info see: https://home.agh.edu.pl/~bszafran/mofit/w1_22.pdf
        const double A_0_0 = 1;
        const double A_0_1 = -dt/2;
        const double A_1_0 = dt/(2*this->mass) * (V(x_iter+dx)+V(x_iter-dx)-2*V(x_iter))/pow(dx,2);
        const double A_1_1 = 1 + dt*this->alpha/2;

        const double b_0 = -F1(x_iter, v_iter, dt);
        const double b_1 = -F2(x_iter, v_iter, dt);

        //Carmer method is used here
        const double W = (A_0_0*A_1_1) - (A_0_1*A_1_0);

        x_iter += ( (b_0*A_1_1)-(b_1*A_0_1) )/W;
        v_iter += ( (b_1*A_0_0)-(b_0*A_1_0) )/W;
    }

    //remember new values
    this->x = x_iter;
    this->v = v_iter;

    retVals.x = x_iter;
    retVals.v = v_iter;
    retVals.Ek = this->mass * retVals.v*retVals.v  / 2;
    retVals.Ep = this->mass * this->V(retVals.x);
    retVals.Esum = retVals.Ek + retVals.Ep;

    return retVals;
}
