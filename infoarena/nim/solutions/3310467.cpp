#include <bits/stdc++.h>

using namespace std;
ifstream fin("pelican.in");
ofstream fout("pelican.out");

char z;
int n,p,c[10001],l[10001] , d[10001] , r[5],R,m,nr;

void recalc()
{
    for(int i=1;i<=p;i++)
    {
        r[0]=  (r[0])%n;
        r[1]=  (r[1])%n;
        if(d[i]==0)
        {
            l[i]=l[i]-r[1];
            c[i]=c[i]-r[0];

            l[i]=(l[i]+n)%n;
            c[i]=(c[i]+n)%n;
        }

        if(d[i]==1)
        {
            l[i]=l[i]-r[0];
            c[i]=c[i]+r[1];

            l[i]=(l[i]+n)%n;
            c[i]=(c[i]+n)%n;
        }

        if(d[i]==2)
        {
            l[i]=l[i]+r[1];
            c[i]=c[i]+r[0];

            l[i]=(l[i]+n)%n;
            c[i]=(c[i]+n)%n;
        }

        if(d[i]==3)
        {
            l[i]=l[i]+r[0];
            c[i]=c[i]-r[1];

            l[i]=(l[i]+n)%n;
            c[i]=(c[i]+n)%n;
        }

        d[i]=(d[i]+R)%4;
    }
    R=0;
    r[0]=0;
    r[1]=0;
    r[2]=0;
    r[3]=0;
}

int main()
{
    fin>>n>>p>>m;

    for(int i=1;i<=p;i++)
    {
        fin>>l[i]>>c[i]>>d[i];
        d[i]=d[i]%4;
    }
    for(int i=1;i<=m;i++)
    {
        fin>>z>>nr;

        if(z=='A')
        {
            if(R<2)
            r[R]+=nr;
            else r[R%2]-=nr;
        }
        if(z=='R')
        {
            R=(R+nr)%4;
        }

        if(z=='Z')
        {
            recalc();
            for(long long i=1;i<=p;i++)
            {
                l[i]=nr/n;
                c[i]=nr%n;
            }
        }
    }

    recalc();
    for(long long i=1;i<=p;i++)
        fout<<l[i]<<' '<<c[i]<<'\n';
    return 0;
}
