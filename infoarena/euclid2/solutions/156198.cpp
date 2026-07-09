#include<fstream.h>
ifstream fin("euclid.in");
ofstream fout("euclide.out");
long n;
long long a,b;
void cmmdc(long long a,long long b){
	long long r;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	fout<<a;
}
void citire(){
	fin>>n;
	for(int i=0;i<n;i++){
		fin>>a>>b;
		cmmdc(a,b);
		fout<<'\n';
	}
}
void main(){
	citire();
	fin.close();
	fout.close();
}