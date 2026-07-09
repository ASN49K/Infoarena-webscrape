#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){
 int t,a,b,d,i;
  fin>>t;
  while(t!=0){
    fin>>a>>b;
    while(b!=0){
        d=a%b;
        a=b;
        b=a;}
    t=t-1;
    fout<<a<<endl;
  }

  fin.close();
  fout.close();
  return 0;
}
