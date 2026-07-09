#include<fstream.h>
using namespace std;
int main()
{ fstream f("euclid2.in",ios::in);
  fstream g("euclid2.out",ios::out);
  int T,a,b,i,r;
  f>>T;
  for(i=1;i<=T;i++)
	{ f>>a>>b;
	 if(a>b) 
    { while(b!=0)
	  { r=a%b;
	    a=b;
		b=r;
	  }
	  g<<a<<endl;
	}
	else
	{	while(a!=0)
		{ r=b%a;
		  b=a;
		  a=r;
		}
		g<<b<<endl;
	}
	}
	f.close(); g.close();
 return 0;
}