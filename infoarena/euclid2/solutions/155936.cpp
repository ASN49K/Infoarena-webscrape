#include<fstream.h>
//using namespace std;
int T, a, b;
int cmmdc(){
  int c;
  while(b){
    c=a%b;
    a=b;
    b=c;
  }
  return a;
}
int main(){
  ifstream f("euclid2.in");
  f>>T;
  int i;
  ofstream g("euclid2.out");
  for(i=0;i<T;i++){
    f>>a>>b;
    g<<cmmdc()<<'\n';
  }
  f.close();
  g.close();
  return 0;
}