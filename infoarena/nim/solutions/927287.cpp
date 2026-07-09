#include<cstdio>
int n,grm,pietre,i,xs,j;
int main()
{
   freopen("nim.in","r",stdin);
   freopen("nim.out","w",stdout);
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
       xs=0;
       scanf("%d",&grm);
       for(j=1;j<=grm;j++)
       {
           scanf("%d",&pietre);
           xs=xs^pietre;
       }
       if(xs) printf("DA\n");
       else printf("NU\n");
   }
    return 0;
}
