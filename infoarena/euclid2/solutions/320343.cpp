#include <fstream.h>

int divizor(long &a,long &b)
	{
	long r,rr;
	while(r!=0)
		{
		if(a>b)
			{
			r=a%b;
			a=b;
			rr=b;
			b=r;
			}
		else
			{
			r=b%a;
			b=a;
			rr=a;
			a=r;
			}
		}
	return rr ;
	}

int main()
	{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	long a,b,n;
	in>>n;
	while(n>0)
		{
		in>>a>>b;
		out<<divizor(a,b)<<"\n";
		n--;
		}
	in.close();
	out.close();
	return 0;
	}
