#include<iostream>
#include<fstream>
using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

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
			second = first % second;
			first = temp;
		}
		return first;
	}
}

int main() 
{
	const char * inFile = "euclid2.in";
	const char * outFile = "euclid.out";

	ifstream fin(inFile);
	ofstream fout(outFile);
	if(!fin || !fout) {
		cout<<"Error opening files!";
		return -1;
	}	
	
	ulong nPairs;
	ulong first, second;

	cin >> nPairs;
	for(ulong i = 0; i < nPairs; i++) {
		cin>>first;
		cin>>second;
		cout<< Iterative::gcd(first, second);
	}

	fout.close();
	fin.close();
}