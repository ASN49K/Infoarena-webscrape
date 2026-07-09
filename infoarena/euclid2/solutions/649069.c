#include <stdio.h>
int a,b,n;
int euclid (int a,int b)
         {  
    if (!b) return a;
         return euclid(b, a%b);
         }
int main(void){
    FILE *fi,*fo;
    fi=fopen("txt.in", "r");
    fo=fopen("txt.out", "w" );
     scanf("%d", &n);
     for(;n;--n)
     {
       scanf("%d %d",&a , &b);
       printf("%d\n",euclid(a, b));
     }
     fclose(fi);
     fclose(fo);
       return 0;
            }
       
