#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t;
int cmmdc (int a,int b){
  if (a==0) return b;
  return cmmdc (b%a,a);
}
void citire(){
    int i,x,y;
    f>>t;
    for(i=1;i<=t;i++){
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
}
int main(){
    citire();
    return 0;
}
