#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a , int b){
  if(a < b){
    swap(a , b);
  }
  int c;
  while(b){
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int main(){
  int n; f >> n;
  for(int i = 1; i <= n; i++){
    int x , y;
    f >> x >> y;
    g << cmmdc(x , y) << endl;
  }
}
