#include<fstream>
#include<iostream>
using namespace std;


long cmmdc(long a, long b)
{
	if(a==0) return b;
	else
	if (b==0) return a;	
	else
	{
	if (a>b) return cmmdc(a%b,b);
		else return cmmdc(a,b%a);
	}
}

int main()
{
	int n;
	long a,b;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>n;
for (int i=1;i<=n;i++)
{
	in>>a>>b;
	out<<cmmdc(a,b)<<'\n';

}
return 0;
}

	