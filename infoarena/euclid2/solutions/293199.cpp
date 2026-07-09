#include<fstream.h>
ifstream intrare ("euclid2.in");
ofstream iesire ("euclid2.out");
int main()
{
	long int a,b,c;
	int t;
	intrare>>t;
	for(int i=1;i<=t;i++)
	{
		intrare>>a>>b;
		while(b!=0)
		{
			c=a%b;
			a=b;
			b=c;
		}
		iesire<<a<<"\n";
	}
	return 0;
}