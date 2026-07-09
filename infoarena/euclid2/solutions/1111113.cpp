#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid.in");
ofstream fout("euclid.out");

int euclid(int a, int b){

	if (a%b==0)
		return b;
	else 
		return euclid(b, a%b);
	
}

int main(){
	int T;
	fin>>T;
	for (int i=0;i<T;i++){
		int a,b;
		fin>>a;
		fin>>b;
		fout<<euclid(a,b)<<"\n";
	}
	return 0;
}
