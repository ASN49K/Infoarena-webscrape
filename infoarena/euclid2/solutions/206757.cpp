#include<fstream.h>
unsigned long i,j,a,b,x;
int main ()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>x;
for (i=0;i<x;i++)
	{f>>a>>b;
	 if (a==b) g<<a<<endl;
	 else {if (a>b) {for (j=b;j>=0;j--)
							if (a%j==0 && b%j==0) {g<<j<<endl;break;}}
			 if (a<b) {for (j=a;j>=0;j--)
							if (a%j==0 && b%j==0) {g<<j<<endl;break;}}
			}
	}
return 0;
}
