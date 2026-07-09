#include <fstream>

using namespace std;

int main()
{
  long long a,b,n,i,r;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f>>n;
  for (i=1;i<=n;i++)
      {
    f>>a>>b;
	  r=1;
	  while (r)
		{ r=a%b;
		  a=b;
		  b=r;
		}
	  g<<a<<endl;
	}
	return 0;
}
