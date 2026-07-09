#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n,a,b,z,aux,ok=0;
	f>>n;
		while(f>>a>>b)
			{if(a>b)
				{aux=a;
				a=b;
				b=aux;}
			for(int i=b;i>=1 && ok==0;i--)
				if(a%i==0 && b%i==0)
					{g<<i<<endl;
					ok=1;}
			ok=0;
			}
	f.close();
	g.close();
}