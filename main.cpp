#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <cmath> // for RAND, and rand
#include <algorithm>
using namespace std;

/*double *Gaussian_Simul(int N) {
    // Seed for random number generation
    unsigned seed = static_cast<unsigned>(time(NULL));
    std::srand(seed);

    // Array to store N Gaussian variables
    double *GS = new double[N];

    // Transform uniform to Gaussian using Box-Muller transform
    for (int i = 0; i < N; i += 2) {
        double u1 = static_cast<double>(std::rand()) / RAND_MAX;
        double u2 = static_cast<double>(std::rand()) / RAND_MAX;

        double z1 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
        double z2 = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);

        GS[i] = z1;
        if (i + 1 < N) {
            GS[i + 1] = z2;
        }
    }

    return GS;
}*/


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

double *BSM(double t,int N, double r, double sigma,double S0){
    double *MBrow;
    MBrow = MB(t,N);
    double *Black_Scholes = new double [N];
    for(int k = 0;k<N;k++){
        Black_Scholes[k] = S0*exp((r-pow(sigma,2)/2)*(static_cast<double>(k*t)/static_cast<double>(N)) + sigma*MBrow[k]);
    }
    return Black_Scholes;
}
double *moyBSM(double t,int N, double r, double sigma,double S0){
    double *MoyBS = new double[N];
    for(int i=0;i<10000;i++){
        double *BSMI;
        BSMI=BSM(t,N,r,sigma,S0);
        for (int j=0;j<N;j++){
            MoyBS[j] = MoyBS[j]+BSMI[j];}
    }
    for (int k=0;k<N;k++){
        MoyBS[k]=MoyBS[k]/10000;
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


double cumulative(double z){
return 0.5 * erfc(-z * sqrt(0.5));
}

double *delta_BSM(double S[],int N, double r, double T,double sigma) {
    double *deltaBSM = new double[N];
    for (int j = 0; j<N;j++) {
        deltaBSM[j] = cumulative((log(S[j])/(K))+(r+pow(sigma,2)/2)*(T-static_cast<double>(T*j)/static_cast<double>(N)) /(sigma*sqrt(T-static_cast<double>(T*j)/static_cast<double>(N))));
    }
    return deltaBSM;
}





//a revoir
int main() {
    double *p;
    int N = 100;
    int S0 = 100;
    p = Gaussian_Simul(N);
    double r = 0.03;
    double sigma = 0.25;
    double T = 1;
    double *s;
    s = moyBSM(T,N,r,sigma, S0);
    double price[N];
    for (int k = 0; k<N; k++){
        price[k] = MonteCarlo(N,phi,p,r,T,sigma,T*k/N,s[k]);}
   double delta[N];
    for (int k =0; k<N-1; k++){
        delta[k] = (price[k+1]-price[k])/(s[k+1]-s[k]);}
    double *Z;
    Z= delta_BSM(s,N,r,T,sigma);
    for (int k = 0; k<N; k++){
        cout<<price[k]<<endl;
        cout<<s[k]<<endl;
        cout<<Z[k]<<endl;
        cout<<delta[k]<<endl;
    }

    return 0;
}





