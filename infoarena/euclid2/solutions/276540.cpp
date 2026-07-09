#include <iostream>
#include <fstream>
using namespace std;

const char * inFile = "euclid2.in";
const char * outFile = "euclid2.out";

ifstream fin(inFile);
ofstream fout(outFile);

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char byte;

namespace Recursive {
	ulong gcd(ulong first, ulong second) {
		if(second == 0)
			return first;
		else
			return Recursive::gcd(second, first%second);
	}
}

namespace Iterative {
	ulong gcd(ulong first, ulong second) {
		ulong temp;
		while(second != 0) {
			temp = second;
			second = first%second;
			first = temp;
		}
		
		return first;
	}
}

int main(int argc, char * argv[]) {
	
	/*if(!fin || !fout) {
		cout << "Error opening files!" << endl;
		return -1;
	}*/
	
	// Do ya thing
	ulong nPairs;
	ulong first, second;
	
	fin >> nPairs;
	for(ulong i = 0; i < nPairs; i++) {
		fin >> first;
		fin >> second;
		fout << Iterative::gcd(first,second) << endl;
	}
	
	fout.close();
	fin.close();
	
	//system("PAUSE");
	return 0;
	
}
