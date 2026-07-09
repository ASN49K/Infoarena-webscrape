#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,a,b;

int gcd(int a,int b){
	int r;
	while(b){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main(){
	fin>>T;
	for(int i=1;i<=T;i++){
		fin>>a>>b;
		fout<<gcd(a,b)<<"\n";
	}
	return 0;
}