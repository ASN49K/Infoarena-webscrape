#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream fin("nim.in");
	ofstream fout("nim.out");
	int cases, nr, num_per_gr,v[100];
	fin >> cases;
	for(int i = 0; i < cases; i++){
		fin >> nr;
		for(int j = 0; j < nr; j++){
			fin >> num_per_gr;
			v[j] = num_per_gr;
		}
		int rez = 0;
		for(int k = 0; k < nr; k++){
			rez = rez ^ v[k];
		}
		if (rez != 0){
			fout <<"DA"<<'\n';
		}else{
			fout <<"NU"<<'\n';
		}

	}
	return 0;
}