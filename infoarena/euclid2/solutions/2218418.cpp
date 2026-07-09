#include <fstream>

using namespace std;

int main()
{
    int t,a,b,c,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=0;i<t;i++)
    {
        f>>a>>b;
        while(b!=0)
        {
          c=a;
          a=b;
          b=c%b;
        }
        g<<a<<endl;
    }
  f.close();
  g.close();
  return 0;
}
