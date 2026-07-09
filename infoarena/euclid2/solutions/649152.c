#include <stdio.h>
int a,b,n;
int euclid (int a,int b)
         {  
    if (!b) return a;
         return euclid(b, a%b);
         }
int main(void){
    
    fopen("euclid2.in", "r+");
    fopen("euclid2.out", "w+" );
     scanf("%d", &n);
     for(;n;--n)
     {
       scanf("%d %d",&a , &b);
       printf("%d\n",euclid(a, b));
     }
     fclose("euclid2.in");
     fclose("euclid2.out");
       return 0;
            }
       
