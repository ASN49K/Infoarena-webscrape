#include <iostream>
#include <cstdio>
using namespace std;
int a[1050],b[1050],n,m,d[1030][1030],sir[1030],nr=0;
void citire()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
}
void matrice()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]==b[j])
            d[i][j]=d[i-1][j-1]+1;
        else
            d[i][j]=max(d[i-1][j],d[i][j-1]);
    }
    for(int i=n,j=m;i;)
    {
        if(a[i]==b[j])
        {
            sir[++nr]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
        else
            i--;
    }
}
void afisare()
{
    printf("%d \n",nr);
    for(int i=nr;i>=1;i--)
        printf("%d ",sir[i]);
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    citire();
    matrice();
    afisare();
    //cout << "Hello world!" << endl;
    return 0;
}
