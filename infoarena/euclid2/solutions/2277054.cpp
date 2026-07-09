#include <fstream>
using namespace std;
int i,T,s[200000],a,b,c;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main() {
  f>>T;
  for(i=1;i<=T*2;i++)
  f>>s[i];
  for(i=1;i<T*2;i++)
  { a=s[i];b=s[i+1];
while(b){
c=a%b;
a=b;
b=c;
}
g<<a<<endl;
i++;
  }

}
