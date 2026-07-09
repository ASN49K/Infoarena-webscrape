#include <stdio.h>
#define maxim(a,b) ((a>b)?a:b)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define Nmax 1024

using namespace std;
int a[Nmax],b[Nmax],d[Nmax][Nmax],sir[Nmax],best;

int main()
{
    int n,m,i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d%d",&n,&m);

    FOR(i,1,n)
     scanf("%d",&a[i]);
    FOR(j,1,m)
     scanf("%d",&b[j]);

    FOR(i,1,n)
     FOR(j,1,m)
       if(a[i]==b[j])
        d[i][j]=1+d[i-1][j-1];
       else d[i][j]= maxim(d[i-1][j],d[i][j-1]);

    for(i=n,j=m;i;)
        if(a[i]==b[j])
            sir[++best]=a[i],--i,--j;
        else
            if(d[i-1][j]<d[i][j-1])
             --j;
            else
             --i;
    printf("%d\n",best);
    for(i=best;i>0;i--)
        printf("%d ",sir[i]);
}

