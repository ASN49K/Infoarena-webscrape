#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t,d,i;
int cmmdc(int a,int b){
	if(b)
		return cmmdc(b,a%b);
	else return a;
}
int main () {
	f>>t;
	
	for(i=1;i<=t;++i){
		f>>a>>b;
		d=cmmdc(a,b);
		g<<d<<"\n";
	}	
	return 0;
}
