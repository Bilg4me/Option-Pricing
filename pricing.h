#ifndef PRICING_H
#define PRICING_H

#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;

inline double* standard_normal_dist(int N)
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

inline double normalCDF(double x) // N(x)
{
    return erfc(-x / sqrt(2)) / 2;
}

/* A basic Brownian Motion with a step of t/N and N values */
inline double* MB(double t, int N){
    double *GS;
    GS  = standard_normal_dist(N);
    double *MB_t = new double [N];
    MB_t[0]=0;
    for (int k = 0; k<N-1;k++){
        MB_t[k+1] = MB_t[k] + GS[k]*sqrt(t/N) ;
    }
    return MB_t;
}

/* Process trajectory of S_t under BSM assumptions */
inline double* trajectory(double t,int N, double r, double sigma,double S0){
    double *MBrow;
    MBrow = MB(t,N);
    double* S_t = new double [N];

    for(int k = 0; k < N; k++){
        S_t[k] = S0*exp((r-pow(sigma,2)/2)*(k*t/N) + sigma*MBrow[k]);
    }

    return S_t;
}


inline double *moyBSM(double t,int N, double r, double sigma,double S0){
    double *MoyBS = new double[N];
    for(int i=0;i<10000;i++){
        double *trajectoryI;
        trajectoryI=trajectory(t,N,r,sigma,S0);
        for (int j=0;j<N;j++){
            MoyBS[j] = MoyBS[j]+trajectoryI[j];}
    }
    for (int k=0;k<N;k++){
        MoyBS[k]=MoyBS[k]/10000;
    }
    return MoyBS;
}


inline double phi(double z, double K){
    double x = z - K;
    return max(x,0.);
}


inline double MonteCarlo(int N, double (*phi)(double z), double X[], double r, double T, double sigma, double t, double x){
    double val = 0;
    for(int i=0; i<N;i++){
        val+=phi(x*exp((r-(pow(sigma,2)/2))*(T-t) + sigma*sqrt(T-t)*X[i]));
    }
    return val/N;
}


inline double *delta_trajectory(double S[],int N, double r, double T,double sigma) {
    double *deltatrajectory = new double[N];
    double K = 30;
    for (int j = 0; j<N;j++) {
        deltatrajectory[j] = normalCDF((log(S[j]/K)+(r+pow(sigma,2)/2)*(T-T*j/N)) /(sigma*sqrt(T-T*j/N)));
    }
    return deltatrajectory;
}

#endif
