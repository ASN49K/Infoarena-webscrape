#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

unsigned long long int cmmdc(unsigned long long int a,unsigned long long int b){
  if(a==0)
  return b;
  else if(b==0)
  return a;
  else return cmmdc(b,a%b);
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
