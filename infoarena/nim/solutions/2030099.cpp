#include<cstdio>
int main(){
   int t,n,a,s,i,j;
   freopen("nim.in","r",stdin);
   freopen("nim.out","w",stdout);
   scanf("%d",&t);
   for(i=1;i<=t;i++){
      scanf("%d",&n);
      s=0;
      for(j=1;j<=n;j++){
         scanf("%d",&a);
         s^=a;
      }
      if(s==0)
         printf("NU\n");
      else
         printf("DA\n");
   }
   return 0;
}
