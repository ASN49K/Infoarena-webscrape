#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

long n, a[100005],initial,l,t,val1,val2;
bitset<100005> viz;

long long cmmdc(long long a, long long b)
{
  if (b==0)
        return a;
  return cmmdc(b,a%b);
}

long long cmmmc(long long x, long long y)
{
    return (x/cmmdc(x,y)*y);
}

int main()
{
    ifstream f("perm2.in");
    ofstream g("perm2.out");
    f >> n;
    for (int i=1; i<=n; i++)
    {
        f >> a[i];
    }
    val1=1;
    for (int i=1; i<=n; i++)
    {
        if (viz[i]==0)
        {
            l=0;
            t=i;
            while (viz[t]!=1)
            {
                viz[t]=1;
                t=a[t];
                l++;
            }
            val2=l;
            val1=cmmmc(val1,val2);
           // cout << val1 <<' '<<val2 << endl;
        }
    }
    g << val1;
    return 0;
}
