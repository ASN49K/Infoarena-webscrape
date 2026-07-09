#include <iostream>
#include <fstream>
using namespace std;

long int cmmdc(long int a,long int b){
  int r,c;
  do{
    c=a/b;
    r=a%b;
    a=b;
    b=r;
    }
  while (b);
  return a;
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
  