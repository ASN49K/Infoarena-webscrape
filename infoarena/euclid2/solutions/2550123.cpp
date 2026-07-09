#include <iostream>
#include <fstream>
using namespace std;

int euclidFunc(int firstNr, int secondNr) {
	while (firstNr % secondNr != 0) {
		int aux = firstNr % secondNr;
		firstNr = secondNr;
		secondNr = aux;
	}
	return secondNr;
}

int main() {

 ifstream myfile;
 myfile.open("euclid2.in");
 ofstream outfile ("euclid2.out");
 int firstNr = 0, secondNr = 0;
 int nrPairs = 0;
 if (myfile.is_open()) {
 	myfile >> nrPairs;
 	
 	for (int i = 0; i < nrPairs; ++i) {
 		myfile >> firstNr >> secondNr;
 		outfile << euclidFunc(firstNr, secondNr) << '\n';
 	}
 }
 myfile.close();
 outfile.close();
 

 return 0;
}