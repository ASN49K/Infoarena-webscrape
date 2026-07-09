#include <iostream>
#include <fstream>
using namespace std;

inline int cmmdc(int a,int b){
  int r;
  while (b!=0){
         r=a%b;
         a=b;
         b=r;
             }
  return a;
  }

int main(){
  ifstream in("euclid2.in");
  ofstream out("euclid2.out");
  int a,b,n;
  in>>n;
  for(int i=0;i<n;++i){
     in>>a>>b;
     out<<cmmdc(a,b)<<endl;
     }

     in.close();
     out.close();
  return 0;
 }
