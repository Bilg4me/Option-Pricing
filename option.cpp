#include "option.h"

Option::Option(double S; double K; double σ; int t; int T; double r)
{
    //ctor
}

Option::~Option()
{
    //dtor
}

Option::Option(const Option& other)
{
    //copy ctor
}

Option& Option::operator=(const Option& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
