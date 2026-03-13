#include <vector>
#include <string>
#include <iostream>
#include "Circuit.h"

using namespace std;

void incidence(Circuit* circuit){
    vector<string> volt_res=circuit->volt_res;
    vector<string> source=circuit->source;
    vector<string> destination=circuit->destination;
    vector<double> values=circuit->values;

    int source_int;
    int destination_int;
    int size=source.size();
    vector<vector<int>> A(circuit->num_nodes, vector<int>(circuit->num_branches, 0));

    for (int i=0; i<size; i++){
        source_int=stoi(source[i]);
        destination_int=stoi(destination[i]);
        A[source_int][i]=1;
        A[destination_int][i]=-1;
    }

    cout << "Incidence matrix (before ground removal):" << endl;
    for (int i=0; i<A.size(); i++){
        for (int j=0; j<A[i].size(); j++){
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    A.erase(A.begin()); //removes ground node

   circuit->A=A;
}
