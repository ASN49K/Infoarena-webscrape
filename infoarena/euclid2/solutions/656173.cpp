#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,a,b,n,r;
int main()
{
    f>>n;
    for (i=1;i<=n;i++)
        {
            f>>a>>b;
            while (a%b!=0)
                {
                    r=a%b;
                    a=b;
                    b=r;
                }
            g<<b<<"\n";
        }
    return 0;
}
