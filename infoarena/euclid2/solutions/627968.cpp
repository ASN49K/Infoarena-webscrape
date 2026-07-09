#include <iostream>
#include <fstream>
using namespace std;

long int cmmdc(long int a,long int b){
  if (!b)
    return a;
  return cmmdc(b,a%b);
  }  	  
  	  

int main()
{ifstream f("euclid2.in",ifstream::in);
long int t,a,b,i;
ofstream g("euclid2.out",ifstream::out);
f>>t;
for(i=1;i<=t;i++)
  {f>>a>>b;
  g<<cmmdc(a,b)<<endl;
  }
f.close();
g.close();
return 0;
}
  