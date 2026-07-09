#include<fstream>

using namespace std;

int T,a,b,i,x;

int cmmdc(int,int);

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	fin>>T;
	
	for(i=1;i<=T;i++)
	{
		fin>>a;
		fin>>b;
		if(a<b){x=a;a=b;b=x;}
		x=cmmdc(a,b);
		fout<<x<<"\n";
	}
	
	return 0;
}

int cmmdc(int m,int n)
{
	int k;
	while(m%n)
	{
		m=m%n;
		k=m;
		m=n;
		n=k;
	}
	return n;
}