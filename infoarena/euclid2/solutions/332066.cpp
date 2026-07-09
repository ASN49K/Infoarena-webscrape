#include<stdio.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))



int euclid(int a,int b)

{ 
    
     if (b==0) return a;  
    return euclid(b, a % b);
}


int main()
{
    int a,b,i,n;
    
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%d\n",&n);
for(i=1;i<=n;i++)
{
   scanf("%d ",&a);
   scanf("%d \n",&b);
   printf("%d\n",euclid(a,b));
}

return 0;
}
