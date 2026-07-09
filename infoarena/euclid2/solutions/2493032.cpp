#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b) {
	if (a == b) return a;
	if (a > b) return euclid(a - b, b);
	else return euclid(a, b - a);
}

int main()
{
	int T, a, b;
	fin >> T;
	for(int i = 0; i < T; i++){
		fin >> a >> b;
		fout << euclid(a, b) << '\n';
	}
	return 0;
}

