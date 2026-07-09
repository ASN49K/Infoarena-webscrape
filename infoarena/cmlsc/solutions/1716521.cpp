#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1024],b[1024],c[1024],c1[1024],n,i,p,j,m,z,ver,maxi,k1,k;
int main()
{
    maxi=0;
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>a[i];
    for(i=1;i<=n;i++)
        fin>>b[i];
        if(m<=n||n>=m)
        {p=1;
        maxi=0;
        while(p<=m)
        {
            z=1;
            k=0;
        for(i=p;i<=m;i++)
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
        if(k>maxi)
        {
            maxi=k;
            for(j=1;j<=maxi;j++)
                c[j]=c1[j];
        }
        p=p+1;
        }
        p=1;
           while(p<=n)
        {
            k=0;
            z=1;
        for(i=p;i<=n;i++)
        {
            ver=1;
            for(j=z;j<=m&&ver;j++)
            if(b[i]==a[j])
            {
                ver=0;
                k=k+1;
                c1[k]=b[i];
                z=j+1;
            }
        }
        if(k>maxi)
        {
            maxi=k;
            for(j=1;j<=maxi;j++)
                c[j]=c1[j];
        }
        p=p+1;
        }  }
        fout<<maxi<<endl;
        if(maxi!=0)
        {
            for(i=1;i<=maxi;i++)
                fout<<c[i]<<"  ";
        }
    fin.close();
    fout.close();
    return 0;
}
