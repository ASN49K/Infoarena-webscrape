#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	long long a,b,t,i=1,r;
	f>>t;
	while(i<=t)
		{
			f>>a>>b;
			while(b!=0)
				{
                                        r=a%b;
					a=b;
					b=r;
				}
                        if(b==0)
				g<<a<<"\n";
                        i++;
		}
	return 0;
}
