#include <iostream>
#include <cmath>
#include <random>
#include <math.h>
#include <list>



using namespace std;

/*

Je veux crée un vecteur de taille n (avec n en entrée), chaque élement de mon vecteur doit être une variable aléatoire qui suit une loi normale.


*/

double normal_distr_centr_red(){

    normal_distribution<double> distrN(0.0, 1.0); // Distribution normale centrée réduite

    random_device rd;

    default_random_engine generator(rd());

    double num = distrN(generator);

    return num;

}




list<double> Brownian_function(int t){

    list<double> Liste = {0}; /* liste avec t éléments valant 0 : [0, 0 ,0 ... t fois] */

    /* On va remplacer ces 0 par les Wi */

    

    for(int i=0; i< t ; i++) {

        double W = sqrt(i+1-1)*normal_distr_centr_red() + Liste.back(); /* quand on modifiera le pas de temps on changera le i+1-i*/


        /* On met la valeur Wi à la place ieme de la liste*/

        Liste.push_back(W);

    }





    return Liste ; /* Return les W0, W1, ..., Wt : on aura plus qu'a les insérer pour avoir un St*/

};


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

cout << " Voici une liste des valeurs à chaque pas de temps d'une fonction brownienne " << endl;

for (double number : Brownian_function(20)) {


    cout<< number << ",";
}



return 0;
}
