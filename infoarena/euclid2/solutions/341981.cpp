#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a,int b) {
	/*
	if (b == 0) return a;
	return cmmdc(b,a % b);
	*/
	if (a == 0) return b;
	while (b != 0) 
		if (a > b) a-=b;
		else b-=a;
	return a;
}

int main() {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	long T;
	int a,b;
	fin >> T;
	for (long t = 0;t < T;++t) 
	{
	fin >> a >> b;
	int c = cmmdc(a,b);
	//if (c == 1) fout << 0 << endl;
	fout << c << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
