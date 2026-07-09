#include <stdio.h>  
int t,i,a,b;   
int euc(int a, int b)  
{  
   if (!b) 
	return a;
   else  
   	return euc(b, a % b);  
 }  
  
int main()  
{  
    freopen("euclid2.in", "r", stdin);  
    freopen("euclid2.out", "w", stdout);  
    scanf("%d", &t);  
    for (i=1;i<=t;i++)  
   {  
    scanf("%d %d", &a, &b);  
    printf("%d\n", euc(a, b));  
   }          
    return 0;  
 }  