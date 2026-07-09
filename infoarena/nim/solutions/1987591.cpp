#include <iostream>
#include <fstream>
using namespace std;

int T,N;

int main() {
	ifstream fin("nim.in");
	ofstream fout("nim.out");
	fin >> T;
	
	while (T--){
		fin >> N;
		int i,res=0,x;
		for (i=1; i<=N; i++){
			fin >> x;
			res^=x;
		}
		
		if (!res) fout << "NU\n";
		else fout << "DA\n";
	}
	return 0;
}
