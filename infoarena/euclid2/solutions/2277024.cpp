#include <iostream>
#include <fstream>

using namespace std;
int i,T,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid( int a, int b)
{
while(a != b)
{
    if(a > b)
        a = a - b; 
    if(b > a)
        b = b - a; 
}

return a;
}
int main() {
  f>>T;
  for(i=1;i<=T*2;i+2)
  {f>>a>>b;
g<<euclid(a,b)<<endl;
  }

}
