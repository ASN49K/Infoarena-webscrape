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
	while (a != b){
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	
	return a;
}
