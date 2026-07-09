#include <iostream>
#include <fstream>
#define fin ("euclid2.in");
#define fout ("euclid2.out");
using namespace std;

int gcd(int a, int b) {
    while(a!=b) {
      if(a>b) {
        a = a - b;
      } else {
        b = b - a;
      }
    }
    return a;
}

int euclid(int a,int  b) {

    int r;

    while( b ) {
      r = a % b;
      a = b;
      b = r;
    }
    return a;
};

int main() { 
    int a,b,n;
    cin>>n;
for(int i=1; i<=n; i++)
{
    fin>>a>>b;
    fout<<euclid(a,b)<<"\n";
}
 
return 0;
}