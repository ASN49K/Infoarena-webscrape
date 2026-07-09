#include<fstream.h>
int main()
{
	long int n,a,b,i,r;
	ifstream in("eulid2.in");
	ofstream out("euclid2.out");
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
		out<<a<<"\n";
	}
	return 0;
}
