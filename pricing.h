#ifndef PRICING_H
#define PRICING_H

#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

/** Generates a N-array of values following N(0,1) **/
inline double* standard_normal_dist(int N)
{
    // Seed for the random number generator using current time
    unsigned seed = static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count());
    default_random_engine gen(seed);

    // Normal distribution
    normal_distribution<double> distribution(0.0, 1.0);

    // Creation of array

    double* Z = new double[N];

    // Generate random numbers from the normal distribution
    for (int i = 0; i < N; ++i)
    {
        Z[i] = distribution(gen);
    }

    return Z;
}

/** Cumulative distribution function of standard normal distribution N(0,1) **/
inline double normalCDF(double x)
{
    return erfc(-x / sqrt(2)) / 2;
}

/** A basic Brownian Motion with a step s and N values **/
inline double* BM(double s, int N)
{
    double* Z;
    Z = standard_normal_dist(N);
    double* B_t = new double [N];
    B_t[0]=0;
    for (int k = 0; k<N-1; k++)
    {
        B_t[k+1] = B_t[k] + Z[k]*sqrt(s/N) ;
    }
    return B_t;
}


#endif
