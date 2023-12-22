#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <cmath> // for RAND, and rand
#include <algorithm>
using namespace std;



double *Gaussian_Simul(int N) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    random_device rd;
     double *GS = new double [N] ;
        normal_distribution<double> distribution (0.0,1.0);
            for (int i=0; i<N; ++i)
                GS[i] = distribution(generator);
        return GS;}

double *MB(double t, int N){
    double *GS;
    GS  = Gaussian_Simul(N);
    double *MB_t = new double [N];
   MB_t[0]=0;
    for (int k = 0; k<N-1;k++){
        MB_t[k+1] = MB_t[k] + GS[k]*sqrt(t/N) ;
    }
    return MB_t;
}

double *BSM(double t,int N, double r, double sigma){
    double *MBrow;
    MBrow = MB(t,N);
     double *Black_Scholes = new double [N];
    for(int k = 0;k<N;k++){
        Black_Scholes[k] = exp((r-pow(sigma,2)/2)*(k*t/N) + sigma*MBrow[k]);
    }
return Black_Scholes;
}
double *moyBSM(double t,int N, double r, double sigma){
  double *MoyBS = new double[N];
  for(i=0;i<10000;i++){
    double *BSMI;
    BSMI=BSM(double t,int N, double r, double sigma);
    for (j=0,j<N,j++){
        MoyBS[j] = MoyBS[j]+BSMI[j];}
  }
  for (k=0,k<N,k++){
    MoyBS[j]=MoyBS[j]/10000;
  }
  return MoyBS;
  }
double K = 34;

double max(double a, double b){
    if (a>=b){
        return a;
    }
    else{
        return b;
    }
}

double phi(double z){
    double x = z - K;
    return max(x,0);
}


double MonteCarlo(int N, double (*phi)(double z), double X[], double r, double T, double sigma, double t, double x){
    double val = 0;
    for(int i=0; i<N;i++){
        val+=phi(x*exp((r-(pow(sigma,2)/2))*(T-t) + sigma*sqrt(T-t)*X[i]));
    }
    return val/N;
}





int main() {
double *p;
int N = 100000;
double x = 50;
//p = Gaussian_Simul(N);
//cout<<MonteCarlo(N,phi,p,0.03,1,0.3,0,x)<<endl;
return 0;
}


