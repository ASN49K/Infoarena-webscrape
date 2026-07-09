#include <iostream>
#include <fstream>
using namespace std;
int a[1030],b[1030];
int i,i1,na,nb,m[1030][1030],n,v[1030];
int main(void)
{
    FILE * f;
    f=fopen("cmlsc.in","r");
    ofstream g("cmlsc.out");
    fscanf(f,"%d%d",&na,&nb);
    for (i=1;i<=na;i++)
        fscanf(f,"%d",&a[i]);
    for (i=1;i<=nb;i++)
        fscanf(f,"%d",&b[i]);
    for (i=1;i<=na;i++)
        for (i1=1;i1<=nb;i1++)
            if (a[i]==b[i1])
                m[i][i1]=m[i-1][i1-1]+1;
            else
                m[i][i1]=max(m[i-1][i1],m[i][i1-1]);
    g<<m[na][nb]<<'\n';
    i=na;
    i1=nb;
    while (m[i][i1]!=0)
    {
        while (m[i-1][i1]==m[i][i1])
            i--;
        while (m[i][i1-1]==m[i][i1])
            i1--;
        n++;
        v[n]=a[i];
        i--;
        i1--;
    }
    for (i=n;i>=1;i--)
        g<<v[i]<<' ';
    g.close();
    return 0;
}
