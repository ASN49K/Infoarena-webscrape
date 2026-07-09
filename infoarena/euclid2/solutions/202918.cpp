#include <fstream.h>
int main()
{
 long t,i,a,b,c;

 ifstream fin("euclid2.in");
 ofstream fout("euclid2.out");

 fin>>t;
 for (i=1; i<=t; i++)
	{
	 fin>>a>>b;
	 if (b>a)
		{
		 c=a;
		 a=b;
		 b=c;
		}
	 while (b!=0)
		{
		 c=a%b;
		 a=b;
		 b=c;
		}
	 fout<<a<<'\n';
	}

 fin.close();
 fout.close();

 return 0;
}