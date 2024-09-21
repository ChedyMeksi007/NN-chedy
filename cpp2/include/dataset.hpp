#ifndef DATA_SET_HPP
#define DATA_SET_HPP

#include "numberimage.hpp"
#include <vector>

using namespace std;

class DataSetDigit{
	public:
	DataSetDigit(
		int size
	       );

	DataSetDigit(
		vector<NumberImage> images,
		int size
	       );

	vector<NumberImage> getImages();
	int getSize();

	void setImages(vector<NumberImage> images);
	void setSize(int size);

	void eatMnistCsv(const char* filename);

	vector<double> getInput(int index);
	vector<double> getTarget(int index);

	private:
		vector<NumberImage> images;
		int size;
};




#endif
