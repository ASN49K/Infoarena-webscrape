#include<iostream.h>
#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{long n,a1,b1,r,i;
f>>n;
for(i=1;i<=n;i++)
{f>>a1;
 f>>b1;
  while(b1)
	{r=a1%b1;
	 a1=b1;
	 b1=r;
	 }
	 g<<a1<<"\n";
  }
  f.close();
  g.close();
  return 0;
  }
