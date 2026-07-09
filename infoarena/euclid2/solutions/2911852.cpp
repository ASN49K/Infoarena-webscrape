#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    long long T,a,b,i;
    f>>T;
    for(i=1;i<=T;i++){
      f>>a>>b;
      while(a!=b){
        if(a>b)
          a-=b;
        if(b>a)
          b-=a;
      }
      g<<a<<endl;
    }
    return 0;
}
