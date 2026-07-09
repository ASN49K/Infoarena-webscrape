#include<iostream>
#include<fstream>
using namespace std;

int cmmdc(int a, int b) {
	int r;
	do{
		
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}

int main() {
	int a,b,i,n;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++)
	{ f>>a>>b;
	  g<<cmmdc(a,b)<<endl;
	}
	f.close();
	g.close();
}