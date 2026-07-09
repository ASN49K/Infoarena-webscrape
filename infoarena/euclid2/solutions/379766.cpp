#include<stdio.h>
int cmmdc(int a,int b)
{
    int a,b,r;
    while(a%b!=0)
    {
      r=a%b;
      a=b;
      b=r;
      }
return b;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid.out","w",stdout);
    int T,i,j,v[200001],x[100001];
    scanf("%d",&T);
    for(i=1,i=2*T,i++;)
          scanf("%d",&v[i]);
    for(j=1,j=T,j++;)
    {     
     x[j]=cmmdc(v[2*j-1],v[2*j]);
     printf("%d",x[j]);
     endl;
     }
     return 0;
     }
          
    
