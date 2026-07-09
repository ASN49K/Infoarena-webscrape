#include<fstream>
using namespace std;
long long int cmmdc(long long int a,long long int b){
	if(a>b){
		a=a+b;
		b=a-b;
		a=a-b;
	}
	long long int r;
	while(a%b!=0 && b!=1 && a!=1){
		r=a%b;
		a=b;
		b=r;
	}
	return b;
}
int main(){
	long long int t;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
	for(long long int i=1;i<=t;i++){
		long long int a,b;
		f>>a>>b;
		g<<cmmdc(a,b)<<'\n';
	}
	return 0;
}

