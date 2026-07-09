#include <stdio.h>
int a,b,n;
int euclid (){
    if (b==0) return a;
        else return euclid(b,a%b);}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
     scanf("%d",&n);
     for(;n=0;n--)
     {
       scanf("%d %d",&a ,&b);
       printf("%d\n",euclid(a,b));
     }
       return 0;
            }
       
