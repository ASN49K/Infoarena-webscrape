#include<fstream>
using namespace std;
long a,b,t,i,r;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(i=1;i<=t;i++)
    {f>>a>>b;
    while(a%b!=0)
    { r=a%b;
      a=b;
      b=r;
    }

    g<<b<<"\n";}
    f.close();
    g.close();
    return 0;

}
