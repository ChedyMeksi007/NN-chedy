#ifndef NUMBER_IMAGE_HPP
#define NUMBER_IMAGE_HPP

#include <vector>

using namespace std;

/*
 * @brief todo
 *
 */
class NumberImage{
	public:
		NumberImage(
				int x,
				int y
			   );
		NumberImage(
			int x,
			int y,
			vector<double> pixels,
			int value
				);

		int getX(){return this->x;}
		int getY(){return this->y;}
		vector<double> getPixels(){return this->pixels;}
		int getValue(){return this->value;}


		void setX(int x){this->x = x;}
		void setY(int y){ this->y = y;}
		void setValue(int value){this->value = value;}
		void setPixels(vector<double> pixels){this->pixels = pixels;}
		void print();
	private:
		int x;
		int y;
		vector<double> pixels;
		int value;


};


#endif
