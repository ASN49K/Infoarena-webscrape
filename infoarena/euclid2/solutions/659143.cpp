# include <fstream>
using namespace std;
int a,b,c,t,i;
int euclid (int x,int y)
{int r=1;
while (r!=0) {r=x%y;
             x=y;
             y=r;}
             if(x==0) return 1;
             else return x;
}
int main()
{ ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f>>t;
  for(i=1;i<=t;i++) { f>>a>>b;
                      g<<euclid(a,b)<<'\n';
                      }

                      }

