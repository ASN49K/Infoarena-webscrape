#include<fstream.h>
#define endl "\n"
int main () {
int a,b,cmmdc,t,i,r;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>t;
for (i=1;i<=t;i++){
	fin>>a>>b;
	r=a%b;
	while (r!=0) {
		a=b;
		b=r;
		r=a%b;
		}
	cmmdc=b;
	fout<<cmmdc;
	fout<<endl;
	}
return 0 ;
}
