#include<cstdio>
 int cmmdc(int i,int j)
   {
    if(!j)
      return i;
    return cmmdc(j,i%j);
   }
 int main()
   {
    int T,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    for(scanf("%d",&T);T;--T)
      {
       scanf("%d %d",&a,&b);
       printf("%d\n",cmmdc(a,b));
      }
    return 0;
   }
