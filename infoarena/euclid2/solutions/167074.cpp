#include <iostream.h>
#include <stdio.h>

int n, a, b;  
   
int gcd(int a, int b)  
{  
   if (!b) return a;  
   return gcd(b, a % b);  
}     
int main(void)  
{  
  freopen("euclid2.in", "r", stdin);  
  freopen("euclid2.out", "w", stdout);  
  
  scanf("%d", &n);
  for (; n; --n)  
    {  
        scanf("%d %d", &a, &b);  
        printf("%d\n", gcd(a, b));  
    }          
  
  fclose(stdin);
  fclose(stdout);
    
  return 0;  
}
