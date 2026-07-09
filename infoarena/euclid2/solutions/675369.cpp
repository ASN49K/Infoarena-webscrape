#include<iostream>
#include<fstream>
using namespace std;

int cmmdc(int a,int b)
{if(a%b==0)
	return b;
 else
	return cmmdc(b,a%b);
}

int main()
{
	long a,b,n,i;
	int c;
	ifstream g("cmmdc.in");
	ofstream t("cmmdc.out");
	g>>n;
	i=1;
	while(i<=n)
	{g>>a>>b;
	 c=cmmdc(a,b);
	 if(c!=1)
	   t<<c<<"\n";
	 else
	   t<<1<<"\n";
	i++;}
	g.close();
	t.close();
	return 0;}
