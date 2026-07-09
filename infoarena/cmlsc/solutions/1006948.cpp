#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int m,n,a[1025],b[1025],v[1025],c[1025],k=1;
    f>>m>>n;
    for(int i=1;i<=m;i++)
        f>>a[i];
    for(int i=1;i<=n;i++)
        f>>b[i] ;
    for(int i=0;i<=n;i++)
        v[i]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i]==b[j])
            {
                v[j]=v[j-1]+1;
                c[k++]=b[j];
            }
            else
                v[j]=max(v[j-1],v[j]);
    g<<v[n]<<"\n";;
    for(int i=1;i<=k-1;i++)
        g<<c[i]<<" ";
    f.close();
    g.close();
}

