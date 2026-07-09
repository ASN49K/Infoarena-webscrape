#include <cstdio>
#include <algorithm>
#define Nmax 1025

using namespace std;

FILE *fin=freopen("cmlsc.in","r",stdin);
FILE *fout=freopen("cmlsc.out","w",stdout);

int m,n,a[Nmax],b[Nmax],af[Nmax],d[Nmax][Nmax];


void dinamica()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
}

void afisare()
{
    int k=0;
    for(int i=m,j=n;i>0;)
        if(a[i]==b[j])
            af[k++]=a[i];
        else
            if(d[i-1][j]<d[i][j-1])
                i--;
            else
                j--;
    for(int i=0;i<k;i++)
        printf("%d ",af[k]);
}

int main()
{
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int j=1;j<=n;j++)
        scanf("%d",b[j]);
    dinamica();
    afisare();
    return 0;
}
