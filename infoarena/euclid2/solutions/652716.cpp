#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int a,b,n,r;
    f>>n;
    for (int i=1;i<=n;i++)
        {f>>a>>b;
        while (a%b!=0)
            {r=a%b;
            a=b;
            b=r;
            }
         g<<b<<"\n";
        }
    return 0;
}
