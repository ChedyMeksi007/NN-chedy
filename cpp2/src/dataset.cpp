#include "../include/dataset.hpp"
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stddef.h>
#include<stdbool.h>
#include <string.h>

DataSetDigit::DataSetDigit(int size) : size(size){

	for(int i= 0;i < size;i++){
		this->images.push_back(NumberImage(28,28));
	}
}

DataSetDigit::DataSetDigit(vector<NumberImage> images,int size) : images(images),size(size){
}

vector<NumberImage> DataSetDigit :: getImages(){
	return this-> images;
}

int DataSetDigit :: getSize(){
	return this->size;
}

void DataSetDigit :: setImages(vector<NumberImage> images){
	this->images = images;
}

void DataSetDigit :: setSize(int size){
	this->size = size;
}

vector<double> DataSetDigit :: getInput(int index){
	return this->images.at(index).getPixels();
}

vector<double> DataSetDigit :: getTarget(int index){
	vector<double> numbers(10,0.00);
	numbers[this->images.at(index).getValue()] = 1.0;
	return numbers;
}

void DataSetDigit::eatMnistCsv(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        std::cerr << "Could not open file " << filename << std::endl;
        exit(-1);
    }

    const int maxRowLength = 3138;
    char row[maxRowLength];
    int imageIndex = 0;

	while (fgets(row, maxRowLength, fp) != NULL) {
        if (imageIndex >= images.size()) {
            std::cerr << "Error: imageIndex " << imageIndex << " is out of range for images vector of size " << images.size() << std::endl;
            fclose(fp);
            exit(-1);
        }
        std::vector<double> pixelValues;
        int columnIndex = 0;
        char* token = strtok(row, ",");
        while (token != NULL) {
            char* endPtr;
            double value = strtod(token, &endPtr);
            if (*endPtr != '\0' && *endPtr != '\n') {
                std::cerr << "Invalid number in CSV file" << std::endl;
                fclose(fp);
                exit(-1);
            }
            if (columnIndex == 0) {
                this->images.at(imageIndex).setValue(value);
            } else {
                pixelValues.push_back(value);
            }
            token = strtok(NULL, ",");
            columnIndex++;
        }
        this->images.at(imageIndex).setPixels(pixelValues);
        imageIndex++;
    }

    fclose(fp);
}
