#include<fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int n,x,y;

int main(){
  int t; f>>t;
  while(t--){
    y=0;
    f>>n;
    for(int i=1;i<=n;i++) {f>>x; y=y^x;}
    if(y) g<<"DA\n";
    else g<<"NU\n";
  }
  return 0;
}
