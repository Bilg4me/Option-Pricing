#include <iostream>
#include <cmath>
#include <random>
#include <math.h>
#include <list>



using namespace std;

/*

Let's create a vector of size n (with n as input), each element of my vector will be a random variable that follows a normal distribution.


*/

double normal_distr_centr_red(){

    normal_distribution<double> distrN(0.0, 1.0); // Normal distribution, centred and reduced

    random_device rd;

    default_random_engine generator(rd());

    double num = distrN(generator);

    return num;

}




vector<double> Brownian_function(int t){

    vector<double> Liste; /* vector with no elements*/

    Liste.push_back(0);

    /* We fill the vector with the Wi values for each indice of time */

    for(int i=0; i< t ; i++) {

        double W = sqrt(i+1-i)*normal_distr_centr_red() + Liste[-1]; /* If we want to change the path of time in the future we will simply have to remplace the i+1-i by an other time step */


        /* We put the Wi value in the ith place in the list*/

        Liste.push_back(W);

    }





    return Liste ; /* Return the W0, W1, ..., Wt : we'll just have to insert them to get a St*/

};

vector<double> BSM_chemin(int t, double r, double vol, double S0){

    vector<double> Liste = Brownian_function(t);

    vector<double> new_Liste;

    for(int i=0; i< Liste.size(); i++){

        double S = S0*exp( (r-0.5*vol*vol)*i + vol*Liste[i]     );

        new_Liste.push_back(S);
    }

    return new_Liste;
}





int main(){

/*
normal_distribution<double> distrN(10.0, 4.0); // Range : [0,5]

random_device rd;

default_random_engine generator(rd());

vector<int> v(20);

for (int i=0; i<800; i++) {

    int num = distrN(generator); 

    if (num >=0 && num <20 )

        v[num]++;
}

for (int i=0; i<20; i++) {

    cout << i << ": " << string(v[i], '*') << endl;
}
*/

cout << " Here is a list of the values at each time step of a Brownian function " << endl;


vector<double> x = Brownian_function(20);

for (int i=0; i< x.size(); i++) {


    cout<< x[i] << ",";
}

vector<double> y = BSM_chemin(20, 0.05, 0.2, 35);

for (int i=0; i< y.size(); i++) {

    cout<< y[i] << ",";


}

return 0;
}
