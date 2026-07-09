#include<stdio.h>
#define InFile "cmlsc.in"
#define OutFile "cmlsc.out"
int n,m,v[1025][3],sir[1025];
int main()
  {int i,x,lg=0,min,max,k;
   freopen(InFile,"r",stdin); freopen(OutFile,"w",stdout);
   scanf("%d %d %d",&n,&m,&x);
   min=max=x;
   if(x<0) v[-x][2]++;
     else v[x][1]++;
   for(i=2;i<=n;i++)
      {scanf("%d",&x);
       if(min>x) min=x;
         else if(max<x) max=x;
       if(x<0) v[-x][2]=1;
         else v[x][1]=1;
      }
  for(i=1;i<=m;i++)
      {scanf("%d",&x);
       if(min>x) min=x;
         else if(max<x) max=x;
       if(x<0) v[-x][2]++;
         else v[x][1]++;
      }
  for(i=min;i<=max;i++)
     {if(i<0) x=-i,k=2;
         else x=i,k=1;
       if(v[x][k]>=2) sir[++lg]=i;
     }
  printf("%d\n",lg);
  for(i=1;i<=lg;i++) printf("%d ",sir[i]);
  }




