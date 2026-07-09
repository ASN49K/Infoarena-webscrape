#include <fstream.h>
using namespace std;
ifstream("euclid2.in");
ofstream("euclid2.out");
int cmmdc( int a, int b)
{ while (a!=b)
  {r=a%b;
  a=b;
  b=r;
}
return a;
}
int main()
{  int n,i,a,b;
	f>>n;
 for (i=1;i<=n;i++)
	{ f>>a>>b;
	 cout<<cmmdc(a,b)<<'\n';
	}