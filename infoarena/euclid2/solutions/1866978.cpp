#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

 int Euclid(int a,int b)
  {
      if(!b)
        return a;
      else
        return Euclid(b,a%b);
  }
int main()
{
   int n,x,y;
    f>>n;
    for(int i=1;i<=n;i++)
    { f>>x>>y;
      g<<Euclid(x,y)<<endl;

    }
    return 0;
}
