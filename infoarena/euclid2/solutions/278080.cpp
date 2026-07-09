include <fstream>   
int n,a,b,i;   
int gcd (int a, int b)   
{ if (!b) return a;   
   return gcd (b,a%b);}   
  
int main()   
{ 
	std::ifstream  f("euclid2.in");   
    std ::ofstream g("euclid2.out");   
  f>>n;   
  for (i=1;i<=n;i++)   
    { f>>a>>b;   
      g<<gcd(a,b)<<"\n";}   
  return 0;   
}  
#include <fstream>
int n,a,b,i;
int gcd (int a, int b)
{ if (!b) return a;
   return gcd (b,a%b);}

int main()
{ 
	std ::ifstream  f("euclid2.in");
    std ::ofstream g("euclid2.out");
  f>>n;
  for (i=1;i<=n;i++)
    { f>>a>>b;
      g<<gcd(a,b)<<"\n";}
  return 0;
}