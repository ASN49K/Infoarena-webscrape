#include<iostream>
#include<fstream>
using namespace std;

typedef unsigned int u_int;
typedef unsigned long u_long;

namespace Recursive {
	u_long gcd(u_long first, u_long second) {
		if(second == 0)
			return first;
		else 
			return Recursive :: gcd(second, first % second);
	}
}

namespace Iterative {
	u_long gcd(u_long first, u_long second)  {
		u_long temp;
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
	const char * outFile = "euclid2.out";

	ifstream fin(inFile);
	ofstream fout(outFile);
	if(!fin || !fout) {
		cout << "Error opening files!" << endl;
		return -1;
	}

	u_long nPairs;
	u_long first, second;

	fin>>nPairs;
	for(u_long i = 0; i < nPairs; i++) {
		fin >> first;
		fin >> second;
		fout << Recursive :: gcd(first, second) << "\n";
	}

	fout.close();
	fin.close();

	return 0;
}