#include "../../include/utils/misc.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

vector<vector<double>> utils::Misc::fetchData(string filepath){

	vector<vector<double>> data;

	ifstream infile(filepath);

	string line;

	while(getline(infile, line)){

		vector<double> dRow;
		string tok;
		stringstream ss(line);

		while(getline(ss,tok,',')){
			dRow.push_back(stof(tok));
		}
	data.push_back(dRow);

	}
	return data;
}
