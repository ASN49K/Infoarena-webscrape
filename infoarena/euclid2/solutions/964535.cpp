#include <iostream>
#include <fstream>
using namespace std;

unsigned int cmmdc(unsigned int fst, unsigned int snd){

	unsigned int t;
	while(snd != 0){
		
		t = snd;
		snd = fst % snd;
		fst = t;
	}
	return fst;
}
int main(){

	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	unsigned int tests,i, fst, snd;
	fin>>tests;
	for(i = 0; i < tests; i++){
		fin>>fst>>snd;
		fout<<cmmdc(fst,snd)<<"\n";
	}
	return 0;
}
