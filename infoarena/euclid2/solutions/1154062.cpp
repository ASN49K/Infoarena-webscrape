#include <fstream>

using namespace std;

//cmmdc(a, b) = cmmdc(b, a % b);

int euclid(int a, int b){
	int c;
	while(b){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(){
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int n;
	int x, y;

	fin >> n;
	for(int i = 0; i < n; i++){
		fin >> x >> y;
		fout<<euclid(x,y)<<"\n";
	}
}