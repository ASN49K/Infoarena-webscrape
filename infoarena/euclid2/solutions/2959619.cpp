#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, x, y;

int euclid(int a, int b);

int main(){
	
	fin >> n; 
	for (auto i = 1; i <= n; ++i){
		fin >> x >> y;
		fout << euclid(x, y) << '\n'; 
	}
	
	return 0;
}

int euclid(int a, int b){
	while (b){
		int rest = a % b;
		a = b;
		b = rest;
	}
	
	return a;
}
