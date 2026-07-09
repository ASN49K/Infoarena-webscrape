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
        {sir[++bst]=a[i];
        j=n+1;}
    printf("%d\n",bst);
    FOR(i,1,bst)
        printf("%d ",sir[i]);
}
