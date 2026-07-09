#include<fstream.h>
int main()
{int T,a,b,i=1;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
for(i=1;i<=T;i++)
{f>>a;
 f>>b;
 while(a!=b)
 {if(a>b)
	a-a-b;
  else
	b=b-a;
  }
  g<<a<<"\n";
  }
return 0;
}