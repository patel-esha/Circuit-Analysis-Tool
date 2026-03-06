#include <vector>
#include <string>
#include <iostream>

using namespace std;

void incidence(){
    vector<string> volt_res;
    vector<string> source={"1","1","2"};
    vector<string> destination={"0", "2", "0"};
    vector<double> values;

    int source_int;
    int destination_int;
    int size=source.size();
    vector<vector<int>> A(size, vector<int>(size, 0));

    for (int i=0; i<size; i++){
        source_int=stoi(source[i]);
        destination_int=stoi(destination[i]);
        A[source_int][i]=1;
        A[destination_int][i]=-1;
    }

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    incidence();
}