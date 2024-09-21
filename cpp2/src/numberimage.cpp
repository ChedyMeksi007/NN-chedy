#include "../include/numberimage.hpp"
#include <vector>
#include <iostream>

NumberImage :: NumberImage(int x,int y) : x(x),y(y),pixels(x*y){
}

NumberImage :: NumberImage(int x, int y, vector<double> pixels,int value){

	this->x = x;
	this->y = y;
	this->value = value;
	this->pixels = pixels;
	this->value = value;
}

void NumberImage :: print(){
	std :: cout << "this number is " << this->value << endl;
	std :: cout << " the dimensions of the image is "<< this->x << " * " << this->y << endl;
	std :: cout << "these are the pixels : " << endl;
	for(int r= 0; r < this->x ; r++){
		for(int c = 0; c< this->y;c++){
			std :: cout << this->pixels.at(c+r*this->x)<< "\t";
		}
		std::cout<< endl;
	}
}
