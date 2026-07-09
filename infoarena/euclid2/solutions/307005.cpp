#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int n,a,b,t,i,x;
	ifstream in("eulid2.in");
	ofstream out("euclid.out");
	in>>n;
	for(i=1;i<=n;i++)
	{
		in>>a;
		in>>b;
		while(b!=0)
		{
			if(b>a)
			{
				x=a;
				a=b;
				b=x;
			}
			x=b;
			b=a%a;
			a=t;
		}
		out<<a;
	}
	return 0;
}