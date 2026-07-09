#include<fstream.h>
using namespace std;
int main()
{ fstream f("euclid.in.txt",ios::in);
  fstream g("euclid.out.txt",ios::out);
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