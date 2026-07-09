#include <cstdio>

int main();
int cmmdc(int,int);

int main()
{   int n,i,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++){scanf("%d %d",&a,&b);printf("%d\n",cmmdc(a,b));};
    return 0;
}

int cmmdc(int a,int b)
{   if(b==0)return a; else
    cmmdc(b,a%b);
}
