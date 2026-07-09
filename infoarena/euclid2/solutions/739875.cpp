#include <fstream>
#define LE 100636
#include <algorithm>
#include <iomanip>
#include <cmath>
#define ll long long
#define lb long double
using namespace std;
ifstream f("cmap.in");
ofstream g("cmap.out");

struct trei
{
  ll x,y,suma;
} A[LE],S1,S2;

ll  n,i,j;
lb minim,D,rez;

ll cmp(trei a,trei b)
{
  return a.suma<b.suma;
}

ll   DIST( trei a,trei b)
{
  return (ll)((ll)(a.y-b.y)*(a.y-b.y)+(ll)(a.x-b.x)*(a.x-b.x));
}


int main()
{
  f>>n;
  for(i=1; i<=n; ++i)
    {
      f>>A[i].x>>A[i].y;
      A[i].suma=A[i].x+A[i].y;
    }

  sort(A+1,A+n+1,cmp);

minim=(ll)1<<62;

  for(i=1; i<=n; ++i)
    for(j=i+1; j<=i+2&&
    j<=n; ++j)
      {
        D=DIST(A[i],A[j]);
        if (D<=minim){
          minim=D;
        }
      }

g<<setprecision(7)<<fixed;
lb de=minim;


  g<<(lb)sqrt((lb)de);


  f.close();
  g.close();
  return 0;
}
