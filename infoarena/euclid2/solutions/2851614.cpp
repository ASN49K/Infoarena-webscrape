#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main()
{
  int t,a,b,i,d;
  fin>>t;
  for(i=1;i<=t;i++){
    fin>>a>>b;
    while(b!=0){
        d=a%b;
        a=b;
        b=d;
    }
    fout<<a<<endl;
  }
  return 0;
}
