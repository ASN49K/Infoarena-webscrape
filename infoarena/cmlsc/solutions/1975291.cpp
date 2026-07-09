#include <fstream>
//#include<iostream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m,n,a[1025],b[1025],c[1025];
void citire()
{
    fin>>m>>n;
    for(int i=1;i<=m;i++)fin>>a[i];
    for(int j=1;j<=n;j++)fin>>b[j];
}
int main()
{
    citire();
    int k=0,kmax=0,ki=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j]){k++;c[k]=j;}
        }
    }
    int nr;
    for(int i=1;i<k;i++ )
    {
        ki=1;
        int x=c[i];
        for(int j=i+1;j<=k;j++)
        {
            if(c[j]>x)
            {
                ki++;
                x=c[j];
            }
        }
        if(ki>kmax){kmax=ki;nr=i;}
    }
    fout<<kmax<<endl;
    int x=c[nr];
    fout<<b[c[nr]]<<' ';
    for(int i=nr+1;i<=k;i++)
    {
        if(c[i]>x)
        {
            fout<<b[c[i]]<<' ';
            x=c[i];
        }
    }
    return 0;
}
