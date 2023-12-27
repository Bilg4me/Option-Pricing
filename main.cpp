#include <iostream>
#include "option.h"


using namespace std;

int main() {
    Call myOption;
    Put yourOption(100,100,0.3,0,1,0.03);
    Option* anOther = &myOption;

    cout << "This is my option " << myOption << " its price is " << myOption.price() << "\n" <<  "This is yours " << yourOption << " its price is " << yourOption.price() << endl;

    cout << "An other one has the same prop than the first " << *anOther << " its price is " << anOther->price() << endl;
    anOther = &yourOption;
    cout << "An other one has now been turn into a put :  " << *anOther << " its price is " << anOther->price() << endl;


    return 0;
}
