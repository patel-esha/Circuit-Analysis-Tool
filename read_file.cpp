#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream> // for istringstream
#include "Circuit.h"
using namespace std;

void read_file(Circuit* circuit)
{
    vector<string> volt_res;
    vector<string> source;
    vector<string> destination;
    vector<double> values;

    ifstream fileIn("netlist.txt"); // fileIn is the name of the input file

    string s;

    while (getline(fileIn, s, '\n'))
    {
      istringstream iss(s);
      string v_r;
      string src;
      string dst;
      double val;
      iss >> v_r >> src >> dst >> val;
      volt_res.push_back(v_r);
      source.push_back(src);
      destination.push_back(dst);
      values.push_back(val);
    }

  /*  for (int i = 0; i < volt_res.size(); i++) 
  {
      cout << volt_res[i] << " " << source[i] << " " << destination[i] << " " << values[i] << endl;
  } */
    circuit->volt_res=volt_res;
    circuit->source=source;
    circuit->destination=destination;
    circuit->values=values;

    // set all counts here
    circuit->num_branches = volt_res.size();

    int max_node = 0;
    for (int i = 0; i < circuit->num_branches; i++){
        max_node = max(max_node, stoi(source[i]));
        max_node = max(max_node, stoi(destination[i]));
    }
    circuit->num_nodes = max_node + 1;

    circuit->num_volt = 0;
    circuit->num_res  = 0;
    for (int i = 0; i < circuit->num_branches; i++){
        if (volt_res[i][0] == 'V') circuit->num_volt++;
        if (volt_res[i][0] == 'R') circuit->num_res++;
    }
}
