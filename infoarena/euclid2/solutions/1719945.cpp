#include<iostream>
#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{
int aux;
if(a>b)
    {aux=a;
    a=b;
    b=aux;}
for(int i=b;i>=1;i--)
    if(a%i==0 && b%i==0)
        return i;
return 0;
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n,a,b,z;
	f>>n;
	while(f>>a>>b)
	{z=cmmdc(a,b);
	g<<z<<endl;	
	}
	f.close();
	g.close();
}