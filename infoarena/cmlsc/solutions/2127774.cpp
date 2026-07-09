#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");



int main()
{
    int m,n,a[100],b[100],c = 0,ok,d[100];
    f>>m>>n;
    for(int i = 0;i < m;i++)
    {
        f>>a[i];
    }
    for(int i = 0;i < n;i++)
    {
        f>>b[i];
    }

    while(m != 0 && n != 0)
    {
        ok = 0;

        if(a[m - 1] == b[n - 1])
        {
            c++;
            m--;
            n--;
            d[c] = a[m];
        }
        else
        {
            for(int i = m - 1;i > 0;i--)
            {
                if(b[n - 1] == a[i])
                {
                    m = i + 1;
                    ok = 1;
                    break;
                }
            }
            if(ok == 0)
            {
                n--;
            }
        }
    }

    g<<c<<"\n";
    for(int i = c;i > 0;i--)
    {
        g<<d[i]<<" ";
    }
    return 0;
}
