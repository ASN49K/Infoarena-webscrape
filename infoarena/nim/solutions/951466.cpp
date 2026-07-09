#include <fstream>

using namespace std;
int t,x,p,i,n,j;
int main()
{
    ifstream f("nim.in");
    ofstream g("nim.out");
    f>>t;
    for (i=1;i<=t;i++)
    {
        f>>n;
          x=0;
          for (j=1;j<=n;j++)
          {
              f>>p;
              x=x^p;
          }
         if (x>0) g<<"DA"<<'\n';
         else g<<"NU"<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
