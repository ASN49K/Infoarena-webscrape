#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

/*
Cel mai mare divizor comun dintre doua numere naturale
a si b este cel mai mare numar
 natural pozitiv d care divide ambele numere.
*/
int Euclid(int a, int b){
	if (b==0) return a; else return Euclid(b, a%b);
}

int main(int argc, char** argv) {
	int numar,a,b;
	fin>>numar;
	for(int i=0; i<numar; i++){
	fin>>a>>b;
    fout<<Euclid(a,b)<<endl;
	}
}
