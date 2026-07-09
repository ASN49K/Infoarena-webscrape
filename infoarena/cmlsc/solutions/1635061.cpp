#include <iostream>
#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");


void cmlsc()
{
    int n, m, i, j, *a, *b, secvmax=0, l, e, ib, *s, *cs, f;
    in>>n>>m;
    a=new int[n+1];
    b=new int[m+1];
    s=new int[n+1];
    cs=new int[n+1];
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];

    for(l=1;l<=n;l++)
    {
        i=l;
        j=1;
        ib=1;
        e=0;
        while(i<=n)
        {
            while(j<=m)
            {
                if(a[i]==b[j])
                {
                    ib++;
                    e++;
                    s[e]=a[i];
                    if(e>secvmax)
                    {
                        for(f=1;f<=e;f++)
                            cs[f]=s[f];
                        secvmax=e;
                    }
                    break;
                }
                j++;
            }
            i++;
            j=ib;
        }
    }
    out<<secvmax<<endl;
    for(i=1;i<=secvmax;i++)
    {
        out<<cs[i]<<" ";
    }
}

int main()
{

cmlsc();


    return 0;
}
