#include <vector>
#include <string>
#include <iostream>
#include "circuit.h"

using namespace std;

void voltage_coeff(Circuit* circuit){
    vector<string> volt_res=circuit->volt_res;
    vector<string> source=circuit->source;
    vector<string> destination=circuit->destination;
    vector<double> values=circuit->values;

    int num_branches = circuit->num_branches;

    int num_nodes = circuit-> num_nodes;
    int num_volt = circuit->num_volt;

    vector<vector<double>> volt_coeff(num_volt, vector<double>(num_nodes - 1, 0));

    int row=0;
    for (int i=0; i<volt_res.size(); i++){
        if (volt_res[i][0] == 'V'){
            int s = stoi(source[i]);
            int d = stoi(destination[i]);
        if (s != 0) volt_coeff[row][s - 1] = +1.0;
        if (d != 0) volt_coeff[row][d - 1] = -1.0;
            row++;
        }
    }
        /*for (int i = 0; i < num_volt; i++) {
        for (int j = 0; j < num_nodes - 1; j++)
            cout << volt_coeff[i][j] << "\t";
        cout << endl;
    } */

    circuit->volt_coeff=volt_coeff;
}
