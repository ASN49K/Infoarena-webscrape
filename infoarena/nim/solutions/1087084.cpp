#include<cstdio>
int main()
{
  freopen("nim.in","r",stdin);
  freopen("nim.out","w",stdout);
  int t,q,n,i,x,v;
  scanf("%d",&t);
  for(q=1;q<=t;q++)
  {
      v=0;
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
          scanf("%d",&x);
          v=v^x;
      }
      if(v==0)
      printf("NU\n");
      else
        printf("DA\n");
  }
    return 0;
}
