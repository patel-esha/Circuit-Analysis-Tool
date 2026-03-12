#include <iostream>
#include <vector>
#include <string>
#include "Circuit.h"
using namespace std;


int main(){
    Circuit* c = new Circuit();

    read_file(c);

    incidence(c);

    voltage_coeff(c);

    curr_coeff(c);

    combine(c);


    // print combined matrix with b
    cout << "Combined matrix [M | b]:" << endl;
    for (int i = 0; i < c->combined.size(); i++){
        for (int j = 0; j < c->combined[i].size(); j++)
            cout << c->combined[i][j] << "\t";
        cout << "| " << c->b[i] << endl;
    }

    delete c;
}