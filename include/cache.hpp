#ifndef CAC_H
#define CAC_H

#include <string>
using std::string;
using std::stoi;

class Cache{
	private:
		int *linha;
	public:
		Cache();
		Cache(string linhasCache);
		~Cache();
};

#endif