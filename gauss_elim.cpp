#include <vector>
#include "Circuit.h"
#include <iostream>
#include <cmath>


using namespace std;

void gauss_elim(Circuit* circuit){
    //Forwards Elimination
    for (int i=0; i<(circuit->combined).size()-1; i++){
        int maxRow = i;
        double maxVal = abs(circuit->combined[i][i]);
        for (int r = i+1; r < circuit->combined.size(); r++){
            if (abs(circuit->combined[r][i]) > maxVal){
                maxVal = abs(circuit->combined[r][i]);
                maxRow = r;
            }
        }
        if (maxVal == 0) return; // singular

        swap(circuit->combined[i], circuit->combined[maxRow]);
        swap(circuit->b[i], circuit->b[maxRow]);
        
        double pivot=circuit->combined[i][i];
        for (int j=i+1; j<(circuit->combined).size(); j++){
            if (circuit->combined[j][i]!=0){
                double factor = (double)circuit->combined[j][i] / pivot;
                for (int k=i; k<(circuit->combined).size();k++){
                    if (k!=(circuit->combined).size()){
                    circuit->combined[j][k]=circuit->combined[j][k]-factor*circuit->combined[i][k];
                    }
                }
                circuit->b[j]=circuit->b[j]-factor*circuit->b[i];
            }
        }

    }
    //Back Substitution
    vector<double> x(circuit->b.size(), NAN);
    x[x.size()-1]=circuit->b[x.size()-1]/circuit->combined[x.size()-1][x.size()-1];
    for (int i=x.size()-2; i>=0; i--){
        double current_b=circuit->b[i];
        for (int j=i+1; j<x.size(); j++){
            current_b-=circuit->combined[i][j]*x[j];
        }
        x[i]=current_b/circuit->combined[i][i];
    }
    circuit->x=x;
}
