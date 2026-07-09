#include<fstream.h>
#define endl '\n'

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
	int a=0,b=0,r=0,n=0,i=0;
	fin>>n;
	for(i=1;i<=n;i++){
		fin>>a>>b;
		if(b>a) {
			r=a;
			a=b;
			b=r;
		}
		r=1;
		while(r){
			r=a%b;
			a=b;
			b=r;
		}
		if(i!=n) fout<<a<<endl;
		else fout<<a;
	}
	return 0;
}
