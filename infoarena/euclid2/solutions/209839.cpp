#include <iostream>
#include <fstream>
//#include <cstring>
//#include <cmath>
using namespace std;
ifstream iFile("euclid2.in");
ofstream oFile("euclid2.out"); 


int cmmdc (long a, long b)
{ if(!b) return a;
  return cmmdc(b, a%b); }


int main(){
int a, b;
int T=0;
 iFile>>T;
 for(int i=0; i<T;i++) 
 {
  iFile>>a; iFile>>b;
  oFile<<cmmdc(a,b)<<endl;
 }

 return 0;
}