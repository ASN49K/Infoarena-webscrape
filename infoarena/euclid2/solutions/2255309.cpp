#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
   int a,b,n;
   f>>n;
  for(int i=1;i<=n;i++)
  { f>>a>>b;
   while(a!=0 and b!=0)
   if(a>b)a=a%b;
   else b=b%a;
  if(a!=0)g<<a<<"\n";else g<<b<<"\n";
  }
   return 0;
}
