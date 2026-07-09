#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned long long int cmmdc(unsigned long long int a,unsigned long long int b){
  unsigned long long int r;
  r=a%b;
  while(r){
    a=b;
    b=r;
    r=a%b;
  }
  return b;
}

int main(){
  unsigned long long int a,b;
  unsigned long long int T;
  fin>>T;
  for(unsigned long long i=1;i<=T;++i){
    fin>>a>>b;
    fout<<cmmdc(a,b)<<'\n';
  }
  return 0;
}
