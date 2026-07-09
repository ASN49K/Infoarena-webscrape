#include<fstream.h>
using namespace std;
int main()
{ fstream f("euclid2.in.txt",ios::in);
  fstream g("euclid2.out.txt",ios::out);
  int T,a,b,i,r;
  f>>T;
  for(i=1;i<=T;i++)
	{ f>>a>>b;
	  while(b!=0)
	  { r=a%b;
	    a=b;
		b=r;
	  }
	  g<<a<<endl;
	}
 return 0;
}