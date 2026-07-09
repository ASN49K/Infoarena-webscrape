#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n,a,b,aux,ok=0;
	f>>n;
	for(int i=1;i<=n;i++)
	{	
		f>>a>>b;
		if(a>b)
		{aux=a;a=b;b=aux;}
		for(int j=b;j>=1 && ok==0;j--)
				if(a%j==0 && b%j==0)
					{g<<j<<endl;
					ok=1;}
		ok=0;
	}
	f.close();
	g.close();
}