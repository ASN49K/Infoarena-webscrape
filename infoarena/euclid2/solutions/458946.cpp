#include<fstream.h>
#define endl "\n"
int main () {
int a,b,cmmdc,t,i;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>t;
for (i=1;i<=t;i++){
	fin>>a>>b;
	while (a!=b) {
		if (a>b) a=a-b;
		else b=b-a;
		}
	cmmdc=a;
	fout<<cmmdc;
	fout<<endl;
	}
return 0 ;
}
