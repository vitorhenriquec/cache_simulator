#include<iostream>
#include<string>
using namespace std;

#include"../include/config.hpp"
#include"../include/cache.hpp"

int main(){
	Config config("config/.config.txt");
	Cache c(config.getLinhasCache());
	return 0;
}