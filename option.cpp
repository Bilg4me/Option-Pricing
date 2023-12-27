#include "option.h"
#include <iostream>

/** ================ Option class ============= **/

Option::Option()
{
    //ctor
    S = 100;
    K = 100;
    T = 1;
    t = 0;
    v = 0.3;
    r = 0.03;
    this->Settenor();

}

Option::Option(double S, double K, double v, double t, double T, double r)
{
    //ctor
    this->S = S;
    this->K = K;
    this->T = T;
    this->t = t;
    this->v = v;
    this->r = r;
    this->Settenor();

}

Option::~Option()
{
    //dtor
}

Option::Option(Option& other)
{
    //copy ctor
    S = other.GetS();
    K = other.GetK();
    T = other.GetT();
    t = other.Gett();
    v = other.Getv();
    r = other.Getr();
    this->Settenor();
}

Option& Option::operator=(Option& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

ostream& operator<<(ostream& os, Option& option)
{
    os << "This option is a " << option.Getoption_type() << " with (S,K) = (" << option.GetS() << "," << option.GetK() << ")";
    return os;
}

/** ================ Call class ============= **/

double Call::price()
{
    double d1 = (log(S/K) + (r + v*v / 2)*tenor) / (v * sqrt(tenor));
    double d2 = d1 - v*sqrt(tenor);
    double c = normalCDF(d1)*S - K*exp(-r*tenor)*normalCDF(d2);
    return c;
}

double Call::payoff(double Z = 0.)
{
    /* Z follow a standard normal distribution N(0,1) */
    double S_K = S*exp((r-(v*v/2))*tenor + v*sqrt(tenor)*Z) - K;
    return max(S_K, 0.);
}

Call::~Call()
{
    //dtor
}


/** ================ Put class ============= **/

double Put::price()
{
    double d1 = (log(S/K) + (r + v*v / 2)*tenor) / (v * sqrt(tenor));
    double d2 = d1 - v*sqrt(tenor);
    double p = (normalCDF(d1)-1)*S - K*exp(-r*tenor)*(normalCDF(d2) -1);
    return p;
}

double Put::payoff(double Z = 0.)
{
    /* Z follow a standard normal distribution N(0,1) */
    double K_S =  K - S*exp((r-(v*v/2))*tenor + v*sqrt(tenor)*Z);
    return max(K_S, 0.);
}

Put::~Put()
{
    //dtor
}
