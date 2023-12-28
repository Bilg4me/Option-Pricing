#include "pricing.h"
#include "option.h"
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

Option::~Option()
{
    //dtor
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

double Option::MonteCarloSimulation(int N)
{

    double y = 0;
    double* Z = standard_normal_dist(N);

    for(int i=0; i<N; i++)
    {
        y += payoff(Z[i]);
    }

    y *= exp(-r*tenor)/N;

    double BSM_price = price();
    double absError = abs(y - BSM_price);
    double errorRate = absError / BSM_price;

    // Displaying results
    cout << "==================== Resultats de la simulation (" << N << ") ====================" << endl;
    cout << "Prix moyen du " << option_type << " (Monte Carlo): " << y << endl;
    cout << "Prix theorique du " << option_type << " : " << BSM_price << endl;
    cout << "Erreur absolue : " << absError << endl;
    cout << "Erreur relative : " << errorRate * 100 << "%" << endl;
    cout << "=====================================================================" << endl;

    return y;
}

double* Option::trajectory(double s, int N)
{

    double* B_t;
    B_t = BM(s,N);
    double* S_t = new double [N];

    for(int k=0; k < N; k++)
    {
        S_t[k] = S*exp((r-v*v/2)*(k*s/N) + v*B_t[k]);
    }
    return S_t;
}


/** ================ Call class ============= **/

double Call::price()
{
    double d1 = (log(S/K) + (r + v*v / 2)*tenor) / (v * sqrt(tenor));
    double d2 = d1 - v*sqrt(tenor);
    double c = normalCDF(d1)*S - K*exp(-r*tenor)*normalCDF(d2);
    return c;
}

double Call::payoff(double Z)
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

double Put::payoff(double Z)
{
    /* Z follow a standard normal distribution N(0,1) */
    double K_S =  K - S*exp((r-(v*v/2))*tenor + v*sqrt(tenor)*Z);
    return max(K_S, 0.);
}

Put::~Put()
{
    //dtor
}
