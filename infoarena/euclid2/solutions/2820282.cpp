#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cinn("euclid2.in");
    ofstream coutt("euclid2.out");
    int n, a, b, r;
    cinn>>n;
    while(n){
      cinn>>a>>b;
      while(b!=0){
        r=a%b;
        a=b;
        b=r;
      }
      coutt<<b<<endl;
      n--;
    }
    return 0;
}
