#include <fstream>
#define DMAX 100001
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t, a, b;

int gcd(int a, int b){
	int r;
	while (b){
		r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main(){
	int i;

	fin >> t;
	for (i = 0; i < t; i++){
		fin >> a >> b;
		fout << gcd(a, b) << '\n';
	}

	return 0;
}