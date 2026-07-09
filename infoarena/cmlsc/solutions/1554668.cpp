#include <iostream>
#include <cstdio>
using namespace std;
int c[1030][1030],n,m,a[1030],b[1030],d[1030],max1=0,imax,jmax,nr=0,e[1024];
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
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
             if(b[i]==a[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                max1=c[i][j];
                imax=i;
                jmax=j;
            }
        else
       c[i][j]=max(max(c[i-1][j],c[i][j-1]),c[i-1][j-1]);
    }
    printf("%d \n",max1);
}
void vector1()
{
    int i=imax,j=jmax,nr=0;
    while(c[i][j]!=0)
    {
        if(b[i]==a[j])
        {
            d[++nr]=a[j];
            i--;
            j--;
        }
        else
        {
            if(c[i-1][j]!=c[i][j])
                j--;
            else
                i--;
        }
    }
    for(int i=max1;i>=1;i--)
        printf("%d ",d[i]);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    construire();
    vector1();
//    cout << "Hello world!" << endl;
    return 0;
}
