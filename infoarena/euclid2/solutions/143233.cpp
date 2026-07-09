#include<fstream>
using namespace std;
long a,b,c;
int main(){
  ifstream f("euclid2.in");
  f>>a>>b;
  f.close();
  while(b){
    c=a%b;
    a=b;
    b=c;
  }
  ofstream g("euclid2.out");
  g<<a<<'\n';
  g.close();
  return 0;
}
