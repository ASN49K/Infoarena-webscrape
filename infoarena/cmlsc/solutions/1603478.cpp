#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, a[1026], b[1026], m, i, j, s[1026], poz, p[1026], t[1026], mx, nr, mxi, v[1026];

int _find(int poz, int x)
{
    while(poz<=m)
    {
        poz++;
        if(b[poz]==x)
            return poz;
    }
    return 0;
}

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            if(s[j]&&s[j]+1>s[i])
            {
                poz=_find(p[j],a[i]);
                if(poz)
                {
                    s[i]=s[j]+1;
                    t[i]=j;
                    p[i]=poz;
                }
            }
        }
        if(!s[i])
        {
            poz=_find(0,a[i]);
            if(poz)
            {
                s[i]=1;
                p[i]=poz;
            }
        }
    }
    mx=0;
    for(i=1;i<=n;i++)
    {
        if(s[i]>mx)
        {
            mx=s[i];
            mxi=i;
        }
    }
    fout<<mx<<'\n';
    nr=0;
    while(mxi)
    {
        v[++nr]=a[mxi];
        mxi=t[mxi];
    }
    for(i=mx;i>=1;i--)
        fout<<v[i]<<" ";
    return 0;
}
