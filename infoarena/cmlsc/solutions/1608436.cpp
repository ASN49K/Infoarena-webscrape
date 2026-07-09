#include <cstdio>
#define Nmax 1025
#define maxim(a,b) ((a>b)?a:b)
#define FOR(i,a,b) for(i=a;i<=b;++i)

using namespace std;


int n,m,a[Nmax],b[Nmax],d[Nmax][Nmax],sir[Nmax],bst;

int main()
{
    int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    FOR(i,1,m)
    scanf("%d",&a[i]);
    FOR(i,1,n)
    scanf("%d",&b[i]);
    FOR(i,1,m)
      FOR(j,1,n)
       if(a[i]==b[j])
        d[i][j]=1+d[i-1][j-1];
       else
        d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    for(i=m,j=n;i;)
        if(a[i]==b[j])
        sir[++bst]=a[i],--i,--j;
        else
            if(d[i-1][j]<d[i][j-1])
              --j;
            else
              --i;
    printf("%d\n",bst);
    for(i=bst;i;--i)
        printf("%d ",sir[i]);
}
