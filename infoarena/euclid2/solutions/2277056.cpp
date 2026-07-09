#include <fstream>
using namespace std;
int i,T,s[200000],a,b,c;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main() {
  f>>T;
  for(i=1;i<=T;i++)
  {f>>a>>b;
while(b){
c=a%b;
a=b;
b=c;
}
g<<a<<"\n";

  }
return 0;
}
