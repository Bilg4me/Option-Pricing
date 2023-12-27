#include <iostream>
#include "option.h"


using namespace std;

int main() {
    Option myOption;
    Option yourOption(100,100,0.25,0.2,1,0.05);
    Option anOther = myOption;

    cout << "This is my option " << myOption << "\n" <<  "This is yours " << yourOption <<endl;

    cout << "An other one has the same prop than the first " << anOther;


    return 0;
}
