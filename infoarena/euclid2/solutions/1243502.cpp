#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main() {
	int n,a,b, rest;
	
	fin>> n;
	for( int i=1; i<=n; i++ ){
		fin>> a >> b;
		while(b!=0){
			rest = a%b;
			a = b;
			b = rest;
		}
		fout<<a<<"\n";
	}
	fin.close();
	fout.close();
return 0;
}
