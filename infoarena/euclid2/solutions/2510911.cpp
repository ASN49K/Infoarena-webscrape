#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
 int main() {
 	int nr1, nr2;
 	fin >> nr1 >>nr2;
 	while(nr1 != nr2) {
 		if(nr1 > nr2)
 			nr1=nr1 - nr2;
 		 if(nr2 > nr1)
 		 	nr2=nr2 - nr1;



 	}
 	fout<<nr1;
 	return 0;
 }
