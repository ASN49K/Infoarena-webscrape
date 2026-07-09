#include <stdio.h>
int a,b,n;
int euclid (int a,int b)
         {  
    if (!b) return a;
         return euclid(b, a%b);
         }
int main(void){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
     scanf("%d", &n);
     for(;n;--n)
     {
       scanf("%d %d",&a , &b);
       printf("%d\n",euclid(a, b));
     }
       return 0;
            }
       
