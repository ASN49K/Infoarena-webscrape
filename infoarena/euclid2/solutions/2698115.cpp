#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
	int T, a, b;
	fin>>T;
	while(T--){
		fin>>a>>b;
		while(b){
			int r=a%b;
			a=b;
			b=r;
		}
		fout<<a<<"\n";
	}
}
