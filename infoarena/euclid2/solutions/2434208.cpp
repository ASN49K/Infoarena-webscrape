#include<iostream>
#include<fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a,int b){
	if(!b)
		return a;
	else
		return cmmdc(b,a%b);
}

int main(){
	int a,b,t;
	fin>>t;
	while(--t){
		fin>>a>>b;
		fout<<cmmdc(b,a%b)<<"\n";
	}
	
}
