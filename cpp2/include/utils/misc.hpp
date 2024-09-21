#ifndef MISC_HPP
#define MISC_HPP


#include <vector>
#include <string>
using namespace std;

namespace utils{

	class Misc{

		public:
			static vector<vector<double>> fetchData(string filepath);
	};
}


#endif
