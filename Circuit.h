#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include <string>

using namespace std;

class Circuit {
public:
    vector<string> volt_res;
    vector<string> source;
    vector<string> destination;
    vector<double> values;
    int num_nodes;
    int num_branches;
    int num_volt;
    int num_res;
    vector<vector<int>>    A;  
    vector<vector<double>> volt_coeff;  
    vector<vector<double>> curr_coeff;  
    vector<vector<double>> combined;
    
    vector<double> b;

    vector<double> x;
};

void read_file(Circuit* circuit);
void incidence(Circuit* circuit);
void voltage_coeff(Circuit* circuit);
void curr_coeff(Circuit* circuit);
void combine(Circuit* circuit);
void gauss_elim(Circuit* circuit);


#endif