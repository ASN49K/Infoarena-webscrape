#include <stdio.h>  
   
long long a, b;  
   
long long cmmdc (long long a, long long b)  
 {  
     if (!b) return a;  
     return cmmdc (b, a%b);  
 }  
   
 int main ()  
 {  
     freopen ("euclid2.in", "r", stdin);  
     freopen ("euclid2.out", "w", stdout);  

     scanf ("%d", &T);
     while (T)
     {	   
        scanf ("%lld %lld", &a, &b);     
        long long R = cmmdc (a, b);  
        printf ("%lld\n", R);
     }  
     return 0;  
 }  