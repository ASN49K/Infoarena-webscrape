#include <iostream>
#include <cstdio>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,b,r,n,i;
int main()
{
 //   std::ios::sync_with_stdio(false);
//    freopen("euclid2.in","r",stdin);
//    freopen("euclid2.out","w",stdout);
 //   cin>>n;
    f>>n;
    for (i=0;i<n;i++)
    {
        f>>a>>b;
        r=a%b;
        if (!r) g<<min(a,b)<<'\n';
        else
        {
            while (b)
            {
                r=a%b;
                a=b;
                b=r;
            }
            g<<a<<'\n';
        }
    }
}
