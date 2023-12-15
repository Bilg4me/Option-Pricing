#ifndef PRICING_H
#define PRICING_H

class MonteCarlo{
private :
    int N;
    double x[] ;
    double (*f)(double s);
public :
    MonteCarlo(double N,double x, double(*f)(double s));
        //destructeur
        ~MonteCarlo(){};
        double moy(double N, double x);





};




#endif
