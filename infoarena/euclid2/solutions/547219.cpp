#include <cstdio> 
 
int t,a,b;   
  
  int cmmdc(int a, int b)   
  {   
       if(!b) return a;   
       return cmmdc(b,a%b);   
  }   
  
  
  int main()   
 {   
  freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);   
   
   
 for(scanf("%d",&t);t;--t)   
  {scanf ("%d %d",&a,&b);  
  printf("%d\n",cmmdc(a,b));   
  }   
  return (0);   
  } 
