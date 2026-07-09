#include<stdio.h>
int i,n,x,y;
int eucl(int a,int b)
{ if(!b)return a;
   return eucl(b,a%b);
}

int main()
{   freopen("euclid2.in", "r", stdin);   
    freopen("euclid2.out", "w", stdout); 
    scanf("%d",&n);  
    for(i=1;i<=n;i++)
     {   
        scanf("%d %d", &x, &y);   
        printf("%d\n", eucl(x, y));   
    }      
   return 0;
}