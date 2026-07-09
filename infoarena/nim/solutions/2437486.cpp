#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream fin("nim.in");
	ofstream fout("nim.out");
	int cases, nr, num_per_gr;
	fin >> cases;
	for(int i = 0; i < cases; i++){
		fin >> nr;
		int rez = 0;
		for(int j = 0; j < nr; j++){
			fin >> num_per_gr;
			rez ^= num_per_gr;
		}
		if (rez != 0){
			fout <<"DA"<<'\n';
		}else{
			fout <<"NU"<<'\n';
		}

	}
	return 0;
}