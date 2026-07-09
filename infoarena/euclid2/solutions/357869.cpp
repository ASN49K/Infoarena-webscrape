# include<iostream.h>
# include<fstream.h>
using namespace std;
int main()
{
    int t,a,b,d,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for (i=2;i<=t+1;i++) {
        f>>a>>b;
        while (a%b)
    {
          d=a%b;
          a=b;
          b=d;
          }
          g<<b<<"\n";
          }
          g.close();
          f.close();
          return 0;
          }
          
          
