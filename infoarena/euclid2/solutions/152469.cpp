#include <fstream.h>
int main()
{ long a,b;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f>>a>>b;
  long r=1;
  while (r)
	{ r=a%b;
	  a=b;
	  b=r;
	}
  g<<a;
  f.close();
  g.close();
  return 0;
}
