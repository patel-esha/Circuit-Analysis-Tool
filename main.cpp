#include <iostream>
#include <vector>
#include <string>
#include "Circuit.h"
using namespace std;


int main(){
    Circuit* c = new Circuit();

    read_file(c);

   /* cout << "Branches:" << endl;
    for (int i=0; i<c->num_branches; i++){
        cout << c->volt_res[i] << " " << c->source[i] << " " << c->destination[i] << " " << c->values[i] << endl;
    } */

    incidence(c);

    voltage_coeff(c);

    curr_coeff(c);

    combine(c);

    gauss_elim(c);
 
    // after forwards elimination, before back sub
    
    /*cout << "Upper triangular:" << endl;
    for (int i=0; i<c->combined.size(); i++){
        for (int j=0; j<c->combined[i].size(); j++){
            cout << c->combined[i][j] << "\t";
        }
        cout << "| " << c->b[i] << endl;
    } */

    cout << "output X:" << endl;
    for (int i=0; i<c->combined.size(); i++){
        cout<<c->x[i]<<' ';
    }

    delete c;
}