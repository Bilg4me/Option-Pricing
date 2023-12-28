#include <iostream>
#include "pricing.h"
#include "option.h"

using namespace std;

int main() {
    Call myCall(100,100,0.3,0,1,0.03);
    int N = 100;
    double s = 10;
    double* S_t;

    S_t = myCall.trajectory(s, N);
    for(int i=0; i < N; i++){
        cout << S_t[i] << endl;
    }
    return 0;
}
