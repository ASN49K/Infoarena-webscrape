#include <fstream>

using namespace std;

int main()
{
    int t,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=0;i<t;i++)
    {
        f>>a>>b;
        while(a!=b)
        {
          if(a>b)a=a-b;
          else  b=b-a;
        }
        g<<a<<endl;
    }
  f.close();
  g.close();
  return 0;
}
