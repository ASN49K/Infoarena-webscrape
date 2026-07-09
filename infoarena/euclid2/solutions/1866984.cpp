#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

 unsigned Euclid(unsigned x, unsigned y)
{
    unsigned r=x%y;
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
   int n,x,y;
    f>>n;
    for(int i=1;i<=n;i++)
    { f>>x>>y;
      g<<Euclid(x,y)<<endl;

    }
    return 0;
}
