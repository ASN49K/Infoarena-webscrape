#include <iostream>
#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int main()
{ int i,t,n,x,s;
   f>>t;
   for(;t;t--)
   { f>>n; s=0;
      for(i=1;i<=n;i++)
      { f>>x; s^=x; }
     g<<(s?"DA":"NU")<<"\n";
   }
    return 0;
}
