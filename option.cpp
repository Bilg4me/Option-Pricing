#include "option.h"
#include <iostream>

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

Option::Option(double S, double K, double v, int t, int T, double r)
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
    os << "This option has a theorical call price of " << option.call_price();
    return os;
}
