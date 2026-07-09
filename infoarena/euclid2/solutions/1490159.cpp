#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t;
int main()
{
    int r,i;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<"\n";
    }
    return 0;
}
