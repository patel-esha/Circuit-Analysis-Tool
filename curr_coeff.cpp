#include <vector>
#include <string>
#include <iostream>
#include "Circuit.h"

using namespace std;

void curr_coeff(Circuit* circuit){
    vector<string> volt_res=circuit->volt_res;
    vector<string> source=circuit->source;
    vector<string> destination=circuit->destination;
    vector<double> values=circuit->values;
    
    int num_branches=circuit->num_branches;
    
    int num_nodes = circuit->num_nodes;

    int num_res = circuit->num_res;
    vector<vector<double>> curr_coeff(num_res, vector<double>(num_nodes-1,0));
   
    int row=0;
    for (int i=0; i <num_branches; i++)
        if (volt_res[i][0]=='R') {
            int s = stoi(source[i]);
            int d = stoi(destination[i]);
            if (s!=0) curr_coeff[row][s-1]=1;
            if (d!=0) curr_coeff[row][d-1]=-1;
            row++;
        }
    
    circuit->curr_coeff = curr_coeff;
   /* for (int i=0; i<num_res; i++){
        for (int j=0; j<num_nodes-1; j++){
            cout<<curr_coeff[i][j]<<' ';
        }
        cout<<endl;
    } */
}

