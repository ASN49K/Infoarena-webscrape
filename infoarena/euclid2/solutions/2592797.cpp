#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid (int a, int b){
	while (a != b){
		if ( a > m){
			a -= b;
		}
		else 
			b -= a;
	}
	return a;
}

int main() {
	int n, m, t;
	fin >> t;
	for (int i = 0; i < t; i++){
	fin >> n >> m;
	fout << euclid(n, m) << endl;;
}
}