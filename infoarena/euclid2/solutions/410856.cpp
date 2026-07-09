#include <fstream.h>
long t,a,b;
long euclid(long x,long y){
	long r;
	while (y){r=x%y; x=y; y=r; }
	return x;
}

int main(){
	long i;
	ifstream fin("euclid2.in");
	fin>>t;
	ofstream fout("euclid2.out");
	for (i=1;i<=t;i++)
	{ fin>>a>>b;
	  fout<<euclid(a,b)<<'\n';
	}
	fin.close();
	fout.close();
	return 0;
}
