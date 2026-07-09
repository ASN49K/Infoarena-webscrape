#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
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
int main(){
	citire();
	fin.close();
	fout.close();
	return 0;
}