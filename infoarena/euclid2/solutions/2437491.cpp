#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int T, a, b, r;
    fin >> T;
	for(int i = 1; i <= T; i++){
		fin >> a >> b;
		while(b){
           r = a%b;
           a = b;
           b = r;
		}
		fout << a <<" "<<'\n';
	}
	return 0;

}
