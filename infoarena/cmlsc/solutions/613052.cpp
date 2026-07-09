#include <cstdio>
#include <algorithm>
#define LMAX 1030

using namespace std;

FILE *fin=freopen("cmlsc.in","r",stdin);
FILE *fout=freopen("cmlsc.out","w",stdout);

int a[LMAX],b[LMAX],n,m;
int M[LMAX][LMAX],af[LMAX];

void citire()
{
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
}

void initializare()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i]==b[j])
                M[i][j]=M[i-1][j-1]+1;
            else
                M[i][j]=max(M[i][j-1],M[i-1][j]);
}

void afisare()
{
    int p=0;
    for(int i=m,j=n;i;)
    {
        if(a[i]==b[j])
        {
            af[p++]=a[i];
            i--;
            j--;
        }
        else
            if(M[i][j-1]<=M[i-1][j])
                i--;
            else
                j--;
    }
   printf("%d\n",p);
   for(int i=p-1;i>=0;i--)
    printf("%d ",af[i]);
}

int main()
{
    citire();
    initializare();
    afisare();
    return 0;
}
