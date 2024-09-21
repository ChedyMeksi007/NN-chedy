

#include <cstdlib>
#include <fstream>
#include <iterator>
#include <ostream>
#include <strstream>
#include <time.h>
#include <streambuf>
#include <vector>


#include "../include/nn.hpp"
#include "../include/numberimage.hpp"
#include "../include/dataset.hpp"
#include "../include/json.hpp"
#include "../include/utils/misc.hpp"

using namespace std;
using json = nlohmann::json;

void printSyntax(){
	cerr << "missing params..." << endl;
}

int main(int argc, char* argv[]){

	if (argc != 2){
		printSyntax();
		exit(-1);
	}

	ifstream configFile(argv[1]);
	string str((std:: istreambuf_iterator<char>(configFile)),(std::istreambuf_iterator<char>()));

	auto config = json::parse(str);


	vector<int > topology= config["topology"];
	double bias = config["bias"];
	string testDataFile = config["testDataFile"];
	string testLabelFile = config["testLabelFile"];
	string weightsFile = config["weightsFile"];

	cout << "topology : " << endl;
	for(int i= 0;i<topology.size();i++){
		cout << topology.at(i) << "\t";
	}
	cout << endl;
	NN* nn = new NN(topology,bias,2,3,1);
	vector<vector<double>> testData = utils::Misc::fetchData(testDataFile);
	vector<vector<double>> testLabel= utils::Misc::fetchData(testLabelFile);

	for(int i = 0;i< 1000;i++){
		nn->setCurrentInput(testData.at(i));
		nn->setCurrentTarget(testLabel.at(i));
		nn->feedForward();
		nn->setErrors();
		double error = nn->error;
		cout << "Error for datapoint at " << i << "  = " << error << endl;

	}

	return EXIT_SUCCESS;
}
