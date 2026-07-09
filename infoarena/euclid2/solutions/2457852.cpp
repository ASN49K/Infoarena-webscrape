#include <iostream>
#include <fstream> 
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main () {
	int t,a,b,i,x;
	fin>>t;
	for (i=1;i<=t; ++i) {
		fin>>a>>b;
		while (b>0) {
			x=a%b;
			a=b;
			b=x;
		}
		fout<<a<<endl;
	}
	return 0;
}
