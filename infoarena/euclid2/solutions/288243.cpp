#include<fstream.h>
int main()
{
 unsigned long n,a,b,i,j,d,r;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 for(i=0;i<n;i++)
		{
		 f>>a>>b;
		 for(d=a,j=b;j!=0;r=d%j,d=j,j=r);
		 g<<d<<"\n";
		}
 f.close();
 g.close();
 return 0;
}

