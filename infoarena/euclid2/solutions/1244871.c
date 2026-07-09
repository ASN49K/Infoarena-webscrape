#include <stdio.h>
#include <stdlib.h>
void divi(){
int a,b;
scanf("%d %d" ,&a , &b);
while(a!=b){
    if (a>b)
        a=a-b;
    else b=b-a;}
printf("%d\n",a);
}
int main()
{int t;
 scanf("%d", &t);
 while(t){
   divi();
    t--;}
    return 0;}
