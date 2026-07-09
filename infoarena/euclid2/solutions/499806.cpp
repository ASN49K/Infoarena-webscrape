#include <fstream>
using namespace std;

int cmmdc(int ,int);

int main(){
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");
  int t,a,b;
  fin>>t;
  for( ; t ; --t){
    fin>>a>>b;
    fout<<cmmdc(a,b)<<"\n";
  }
  return 0;
}


int cmmdc(int a,int b){
  while(a%b){
    int r = a%b;
    a=b;
    b=r;
  }
  return b;
}
