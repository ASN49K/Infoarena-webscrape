#include<fstream.h>
#include<math.h>
long t,a,b,r,i;
int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>a>>b;
		do
		{
			r=a%b;
			a=b;
			b=r;
		}
		while(r);
		fout<<a<<"\n";
	}
	return 0;
}
