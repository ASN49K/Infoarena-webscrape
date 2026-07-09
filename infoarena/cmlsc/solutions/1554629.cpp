#include <iostream>
#include <cstdio>
using namespace std;
int c[1030][1030],n,m,a[1030],b[1030],d[1030],max1=0;
void citire()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int j=1;j<=m;j++)
        scanf("%d",&b[j]);
}
void construire()
{
    for(int i=0;i<=n;i++)
        c[i][0]=0;
    for(int i=0;i<=m;i++)
        c[0][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                d[c[i][j]]=a[i];
                max1=c[i][j];
            }
        else
           c[i][j]=max(max(c[i-1][j],c[i][j-1]),c[i-1][j-1]);
    }
}
void afisare()
{
    printf("%d \n",max1);
    for(int i=1;i<=max1;i++)
        printf("%d ",d[i]);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    construire();
    afisare();

//    cout << "Hello world!" << endl;
    return 0;
}
