#include <iostream>
#include <fstream>
using namespace std;

inline void calc(long a,long b, ofstream & out)
{
	if(b==0)
		out<<a<<"\n";
	else
	{
		int a1,b1;
		while(a%b!=0)
		{
			a1=b;
			b1=a%b;

			a=a1;
			b=b1;
		}
		out<<b<<"\n";
	}
}

int main()
{
	long n,i,j,a,b,c;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>n;
	for(i=1;i<=n;i++)
	{
		in>>a>>b;
		calc(a,b,out);
	}

	out.close();
	return 0;
}