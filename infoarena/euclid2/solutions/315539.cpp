#include <stdio.h>
int N,i;
long A,B;
long CMMDC(long x,long y)
{
  if(!y) return x;
  return CMMDC(y,x%y);
}  
int main()
{
    freopen("euclid2.in","r",stdin);freopen("euclid2.out","w",stdout);
    scanf("%d",&N);
    for(i=0;i<N;++i)
       {
        scanf("%ld %ld",&A,&B);
        printf("%ld\n",CMMDC(A,B));
       }
 return 0;
}       
        
    
