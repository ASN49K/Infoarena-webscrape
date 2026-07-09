#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
 int x,y,n;
 int Euclid(int x, int y)
{
    int r=x%y;
    while(r)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}
int main()
{
   
    f>>n;
    for(int i=1;i<=n;i++)
    { f>>x>>y;
      g<<Euclid(x,y)<<endl;

    }
    return 0;
}
