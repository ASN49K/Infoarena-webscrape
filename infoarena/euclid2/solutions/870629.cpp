#include<iostream>
#include<fstream>
using namespace std;
main(){
	ifstream f1("euclid2.in");
	int t,v[10000],i,a,b;
	f1>>t;
	for(i=0;i<t;i++)
	{
		f1>>a>>b;
		while(a!=b)
			if(a>b)
				a=a-b;
			else
				b=b-a;
		v[i]=a;
	}
	ofstream f2("euclid2.out");
	for(i=0;i<t;i++)
		f2<<v[i]<<'\n';
}	