#include <iostream>
#include <fstream>
#include<stdio.h>
//#include <cstring>
//#include <cmath>
using namespace std;
ifstream iFile("euclid2.in");


int cmmdc (long a, long b)
{ if(!b) return a;
  return cmmdc(b, a%b); }


int main(){
int a, b;
int T=0;
freopen("euclid2.out", "w", stdout);  
 iFile>>T;
 for(int i=0; i<T;i++) 
 {
  iFile>>a; iFile>>b;
  printf("%d\n", cmmdc(a,b));//oFile<<cmmdc(a,b)<<endl;
 }

 return 0;
}