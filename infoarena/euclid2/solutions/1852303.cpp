#include <fstream>

using namespace std;
ifstream f1("euclid2.in");
ofstream f2("euclid2.out");
int main()
{   int n,x,y,r,i;
    f1>>n;
    for(i=1;i<=n;i++)
      {f1>>x>>y;
       while(y)
          {r=x%y;
           x=y;
           y=r;
          }
       f2<<x<<"\n";
      }
    return 0;
}
