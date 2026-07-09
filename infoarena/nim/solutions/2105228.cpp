#include <fstream>
using namespace std;
ifstream f ("nim.in");
ofstream g ("nim.out");
string sol[2]={"NU","DA"};
int t,n,x,y;
int main()
{
    f>>t;
    while(t--)
    {
          f>>n;
          x=0;
          while(n--)
          {
                f>>y;
                x^=y;
          }
          if(x) x=1;
          g<<sol[x]<<'\n';
    }
    return 0;
}
