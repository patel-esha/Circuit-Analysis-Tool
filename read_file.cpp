#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream> // for istringstream
using namespace std;

void read_file()
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

}



int main()
{
  read_file();
}