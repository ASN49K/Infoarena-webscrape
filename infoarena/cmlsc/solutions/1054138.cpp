#include <iostream>
#include<fstream>
using namespace std;
int l[111][111],a[111],b[111],c[111],k;
int maxim(int a,int b)
{
    int max;
    if(a>=b)
     max=a;
    else
    max=b;
    return max;
}
int construire(int i,int j)
{
    if(i>=1 && j>=1)
    {
        if(a[i]==b[j])
        {
            construire(i-1,j-1);
            k++;
            c[k]=a[i];
        }
        else
        {
            if(l[i-1][j]>l[i][j-1])
                construire(i-1,j);
            else
                construire(i,j-1);
        }
    }
}
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m,i,j;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            l[i][j]=0;
            if(a[i]==b[j])
            l[i][j]=1+l[i-1][j-1];
            else
            l[i][j]=maxim(l[i-1][j],l[i][j-1]);

        }
    }
    k=0;
    construire(n,m);
    g<<k<<" ";
    g<<endl;
    for(i=1;i<=k;i++)
    g<<c[i]<<" ";
    return 0;
}
