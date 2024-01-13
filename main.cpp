#include <iostream>
#include "pricing.h"
#include "option.h"

using namespace std;

int main() {
    Call myOption;
    int N = 20;
    double s = 1e-1;
    double* delta_t;

    delta_t = myOption.delta_trajectory(s, N);
    cout << myOption << " le prix de l'option " << endl;
    myOption.MonteCarloSimulation(1e6, true);
//    for(int i=0; i < n; i++){
//        cout << delta_t[i] << endl;
//    }
    return 0;
}
