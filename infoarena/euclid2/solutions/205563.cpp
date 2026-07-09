#include<stdio.h>
int t,i,a,b,j;
int cmmd(int x,int y)
{int r=1;
  while(r>0)
   { r=x%y;
     x=y;
     y=r;
     }
  return x;}
     
int main()
{ freopen("euclid2.in","r",stdin);
  freopen("euclid2.out","w",stdout);
  scanf("%d",&t);
  for(i=1;i<=t;i++)
  { scanf("%d%d",&a,&b);
   if(b>a){ j=b;
            b=a;
            a=j;}
         j=cmmd(a,b);
    printf("%d\n",j);
    }
return 0;
}

