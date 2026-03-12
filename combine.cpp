#include <vector>
#include <string>
#include <iostream>
#include "Circuit.h"

void combine(Circuit* circuit){
    int nodes=circuit->num_nodes-1;
    int num_volt=circuit->num_volt;
    int num_res=circuit->num_res;
    int size=nodes+num_volt+num_res;

    circuit->combined = vector<vector<double>>(size, vector<double>(size, 0));
    circuit->b=vector<double>(size,0);

    //KCL rows
    for (int i=0; i<nodes; i++){
    for (int j=0; j<circuit->num_branches; j++){
            circuit->combined[i][nodes+j]=circuit->A[i][j];
        }
    }

     // voltage coefficient rows
    for (int i=0; i<num_volt; i++){
        for (int j=0; j<nodes; j++){
            circuit->combined[nodes+i][j]=circuit->volt_coeff[i][j];
        }
    }
     
    int res_counter=0;
    for (int i=0; i<circuit->num_branches; i++){
        if (circuit->volt_res[i][0]=='R'){
            for (int j=0; j<nodes; j++){
                circuit->combined[nodes+num_volt+res_counter][j]=circuit->curr_coeff[res_counter][j];
            }
            circuit->combined[nodes+num_volt+res_counter][nodes+i]=-(circuit->values[i]);
            res_counter++;
        }
    }

    int volt_counter=0;
    for(int i=0; i<circuit->num_branches;i++){
        if (circuit->volt_res[i][0]=='V'){
            circuit->b[nodes+volt_counter]=circuit->values[i];
            volt_counter++;
        }
    }
}
