#include<fstream>
#include<iostream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],c[1025],p[1025],n,m,maxi,d[1025],i,j,k,poz[1025];
void afisare(int p)
{
    if(poz[p]!=0)
        afisare(poz[p]);
    g<<b[p]<<" ";
}
int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    for(i=1; i<=n; i++)
    {
        maxi=0;
        for(j=1; j<=m; j++)
            if(a[i]==b[j] && d[j]==0)
            {
                p[j]=i;
                poz[j]=0;
                break;
            }
        for(k=1; k<j; k++)
            if(d[k]>maxi && c[p[k]]>maxi && p[k]<i)
            {
                maxi=d[k];
                poz[j]=k;
            }
        c[i]=d[j]=maxi+1;
    }
    int afis;
    maxi=0;
    for(i=1; i<=m; i++)
        if(d[i]>maxi)
        {
            maxi=d[i];
            afis=i;
        }
    g<<maxi<<endl;
    afisare(afis);
}
