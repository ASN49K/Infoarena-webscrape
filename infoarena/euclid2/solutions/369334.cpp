#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned long n,a,b,i;
int main(){
	fin>>n;
	for(i=1;i<=n;i++){
		fin>>a>>b;
		while(a!=0 && b!=0){
			if(a>b) a=a%b;
			else b=b%a;
		}
		if(a==0) fout<<b<<'\n';
		else fout<<a<<'\n';
	}
	fin.close();
	fout.close();
	return 0;
}