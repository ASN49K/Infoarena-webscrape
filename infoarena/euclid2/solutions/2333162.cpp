#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int Euclid(int a, int b){
	if (b==0) return a;
	return Euclid(b, a%b);
}

int main(int argc, char** argv) {
	int numar,a,b;
	fin>>numar;
	while(numar){
	fin>>a>>b;
    fout<<Euclid(a,b)<<"\n";
	numar--;	
	}
}
