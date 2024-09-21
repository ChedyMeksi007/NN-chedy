#include <cstdlib>
#include <fstream>
#include <iterator>
#include <ostream>
#include <strstream>
#include <time.h>
#include <streambuf>
#include <vector>


#include "../include/main.hpp"
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
	double learningRate = config["learningRate"];
	double momentum = config["momentum"];
	string trainingFile = config["trainingFile"];
	string labelsFile = config["labelsFile"];
	string weightsFile = config["weightsFile"];
	int epoch = config["epoch"];

	NN* nn = new NN(topology,learningRate,momentum);
	vector<vector<double>> trainingData = utils::Misc::fetchData(trainingFile);
	vector<vector<double>> labelData = utils::Misc::fetchData(labelsFile);

	cout << "training data size = " << trainingData.size()<< endl;
	cout << "training labels size = "<< labelData.size() << endl;

	for(int e = 0; e<epoch;e++){
		cout << "Epoch : " << e << endl;
		for(int i = 0; i< trainingData.size();i++){
			nn->train(trainingData.at(i),labelData.at(i),learningRate,momentum);
		}

			cout << "overall Error is " << nn->error  << endl;
	}

	cout << "Done Writing to " << weightsFile << endl;
	nn->saveWeights(weightsFile);
}
