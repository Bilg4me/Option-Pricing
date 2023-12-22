#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <cmath> // for RAND, and rand

using namespace std;


double MonteCarlo(int N, double(*f)(double z), double x[]){
    double val = 0;
    for(int i=0; i<=N;i++){
        val+=f(x[i]);
    }
    return val/N;
}


double fct(double z){
    return z;
}

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator (seed);

double *Gaussian_Simul(int N) {
    random_device rd;
     double *GS = new double [N] ;
        normal_distribution<double> distribution (0.0,1.0);
            for (int i=0; i<N+1; ++i)
                GS[i] = distribution(generator);
        return GS;}

double *MB(double t, int N){
    double *GS;
    GS  = Gaussian_Simul(N);
    double *MB_t = new double [N];
   MB_t[0]=0;
    for (int k = 0; k<N;k++){
        MB_t[k+1] = MB_t[k] + GS[k]*sqrt(t/N) ;
    }
    return MB_t;
}

double *BSM(double t,int N, double r, double sigma){
    double *MBrow;
    MBrow = MB(t,N);
     double *Black_Scholes = new double [N];
    for(int k = 0;k<N;k++){
        Black_Scholes[k] = exp((r+pow(sigma,2)/2)*(k*t/N) + sigma*MBrow[k]);
    }
return Black_Scholes;
}



int main() {
double *p;
int N = 100;
p = BSM(1,N,0,1);
    for (int i=0;i<N;i++){
    cout<<*(p + i) <<endl;}

return 0;
}

