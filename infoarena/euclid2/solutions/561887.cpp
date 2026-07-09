#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long n, a[100001], x, y, r, i;
int main()
{ f>>n;
  for(i=1; i<=n; i++) { f>>x>>y;
                        while(y) { r=x%y;
                                   x=y;
								   y=r;
						         }
						g<<x<<"\n";
                      }
  f.close();
  g.close();
  return 0;
}
