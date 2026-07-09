#include <cstdio> 
 #include<fstream>
int t,a,b;   
  
  int cmmdc(int a, int b)   
  {   
       if(!b) return a;   
       return cmmdc(b,a%b);   
  }   
  
  
  int main()   
 {   
  freopen("euclid2.in","r",stdin);
std::ofstream fout("euclid2.out");   
   
   
 for(scanf("%d",&t);t;--t)   
  {scanf ("%d %d",&a,&b);  
  fout<<cmmdc(a,b)<<'\n';   
  }   
  return (0);   
  } 
