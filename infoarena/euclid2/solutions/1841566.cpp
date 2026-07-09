#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int n,i,a,b,r;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        while(a%b)
        {
            r=a%b;a=b;b=r;
        }
        g<<b<<'\n';
    }
    return 0;
}
