#include<fstream.h>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	int a,b,r,i,t,x,y;
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>x>>y;
                a=x;
                b=y;
		r=a%b;
		while(r!=0)
		{     r=a%b;
			a=b;
			b=r;
			
		}
	 fout<<b<<'\n';
	}
	return 0;
}