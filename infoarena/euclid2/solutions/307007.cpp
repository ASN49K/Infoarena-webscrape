#include<fstream.h>
int main()
{
	long int n,a,b,t,i,x;
	ifstream in("eulid2.in");
	ofstream out("euclid.out");
	in>>n;
	for(i=1;i<=n;i++)
	{
		in>>a;
		in>>b;
		while(b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		out<<a;
	}
	return 0;
}