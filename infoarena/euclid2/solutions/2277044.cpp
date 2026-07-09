#include <iostream>
#include <fstream>

using namespace std;
int i,T,s[200000];
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid( int a, int b)
{ int c;
while(b){
c=a%b;
a=b;
b=c;
}
return a;
}
int main() {
  f>>T;
  for(i=1;i<=T*2;i++)
  f>>s[i];
  for(i=1;i<T*2;i++)
  {
g<<euclid(s[i],s[i+1])<<endl;
i++;
  }

}
