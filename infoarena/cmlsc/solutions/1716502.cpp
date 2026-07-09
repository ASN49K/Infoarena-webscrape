#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1024],b[1024],c[1024],c1[1024],n,i,j,m,z,ver,maxi,k1,k=0;
int main()
{
    maxi=0;
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
    if(n<m)
    {
        z=1;
       for(i=1;i<=n;i++)
       {
           ver=1;
           for(j=z;j<=m&&ver;j++)
            if(b[i]==a[j])
           {
               ver=0;
               k=k+1;
               c[k]=b[i];
               z=j+1;
           }
       }

    }
   else if(n>m)
    {
        z=1;
        for(i=1;i<=m;i++)
        {
            ver=1;
            for(j=z;j<=n&&ver;j++)
                if(a[i]==b[j])
            {
                ver=0;
                k=k+1;
                c[k]=a[i];
                z=j+1;
            }
        }
    }
    else if(n==m)
    {
        z=1;
        for(i=1;i<=m;i++)
        {
            ver=1;
            for(j=z;j<=n&&ver;j++)
            if(a[i]==b[j])
            {
                ver=0;
                k=k+1;
                c1[k]=a[i];
                z=j+1;
            }

        }
        maxi=k;
        k=0;
        z=1;
        for(i=1;i<=n;i++)
        {
            ver=1;
            for(j=z;j<=m&&ver;j++)
            if(b[i]==a[j])
            {
                ver=0;
                k=k+1;
                c[k]=b[i];
                z=j+1;
            }
        }
    }
    if(k>=maxi)
    {fout<<k<<endl;
    if(k!=0)
    {for(i=1;i<=k;i++)
        fout<<c[i]<<"  ";}}
    else
    {
        fout<<maxi<<endl;
        if(maxi!=0)
        {
            for(i=1;i<=maxi;i++)
                fout<<c1[i]<<"  ";
        }
    }
    fin.close();
    fout.close();
    return 0;
}
