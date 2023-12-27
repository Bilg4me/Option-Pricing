#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include <random>
#include <chrono>

using namespace std;


double* standard_normal_dist(int N)
{
    // Seed for the random number generator using current time
    unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
    default_random_engine gen(seed);

    // Normal distribution
    normal_distribution<double> distribution(0.0, 1.0);

    // Creation of array

    double* z = new double[N];

    // Generate and print random numbers from the normal distribution
    for (int i = 0; i < N; ++i) {
        z[i] = distribution(gen);
    }

    return z;
}

double normalCDF(double x) // N(x)
{
    return erfc(-x / sqrt(2)) / 2;
}

double call_price(double S, double K, double v, int t, int T, double r){
    double tau = static_cast<double>(T-t);
    double d1 = (log(S/K) + (r + v*v / 2)*tau) / (v * sqrt(tau));
    double d2 = d1 - v*sqrt(tau);
    double c = normalCDF(d1)*S - K*exp(-r*tau)*normalCDF(d2);
    return c;

}

double put_price(double S, double K, double v, int t, int T, double r){
    double tau = static_cast<double>(T-t);
    double d1 = (log(S/K) + (r + v*v / 2)*tau) / (v * sqrt(tau));
    double d2 = d1 - v*sqrt(tau);
    double c = (normalCDF(d1)-1)*S - K*exp(-r*tau)*(normalCDF(d2)-1);
    return c;

}

#endif // TOOLS_H_INCLUDED
