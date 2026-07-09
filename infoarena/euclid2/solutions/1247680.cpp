#include<fstream>
//#include<iostream>
using namespace std;
int main() {
	int n,a,b;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>n;
	while(n) {
		fin>>a>>b;
		while(a!=b) 
			if(a>b) a=a-b;
			else b=b-a;
		fout<<a<<"\n";
		n--;
	}
	fin.close();
	fout.close();
	return 0;
}
