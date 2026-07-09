#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    int a[1025],b[1025],l[1025],m,n,i,k,j,max,mx,t,x;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>m>>n; for(i=1;i<=m;i++) f>>a[i]; for(i=1;i<=n;i++) f>>b[i]; f.close(); //DATE DE INTRARE

    //g<<"a=|"; for(i=1;i<=m;i++) g<<a[i]<<"|"; g<<"\n";
    //g<<"b=|"; for(i=1;i<=n;i++) g<<b[i]<<"|"; g<<"\n";

    if(m>n)
    {
        k=m;
        mx=0;
        for(i=1;i<=n;i++) l[i]=0;
        for(i=n;i>=1;i--)
        {
            for(j=k;j>=1;j--)
            {
                if(b[i]==a[j])
                {
                    //g<<"VALOARE COMUNA "<<a[j]<<"\n";
                    l[i]=mx+1;
                    mx++;
                    k=j;
                }
            }
        }
        //AFISARE
        max=l[1]; t=1;
        for(i=2;i<=n;i++)
            if(l[i]>max) { l[i]=max; t=i; }
        for(i=t;i<=n;i++)
            if(l[i]==max)
            {
                mx=l[i];
                g<<b[i]<<" ";
                for(j=i+1;j<=n;j++)
                    if(l[j]==mx-1)
                    {
                        g<<b[j]<<" ";
                        mx--;
                    }
            }

    }
    else
    {
        k=n;
        mx=0;
        for(i=1;i<=m;i++) l[i]=0;
        for(i=n;i>=1;i--)
        {
            for(j=k;j>=1;j--)
            {
                if(a[i]==b[j])
                {
                    //g<<"VALOARE COMUNA "<<a[j]<<"\n";
                    l[i]=mx+1;
                    mx++;
                    k=j;
                }
            }
        }
        //AFISARE
        max=l[1]; t=1;
        for(i=2;i<=m;i++)
            if(l[i]>max) { l[i]=max; t=i; }
        for(i=t;i<=m;i++)
            if(l[i]==max)
            {
                mx=l[i];
                g<<a[i]<<" ";
                for(j=i+1;j<=m;j++)
                    if(l[j]==mx-1)
                    {
                        g<<a[j]<<" ";
                        mx--;
                    }
            }

    }


   // g<<"k="<<k<<"\n";
     //g<<"L= "; for(i=1;i<=n;i++) g<<l[i]<<" "; g<<"\n";
    g<<"\n";
    g.close();
    return 0;
}
