#include <iostream>

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

int main(int argc, char const *argv[]) { int v1[10001],v2[10001],n
cin>>n;
for(int i=1; i<=n; i++)
{
    cin>>v1[i]>>v2[i];
}

 for(int i=1; i<=n; i++)
{
    cout<<cout<<euclid(v1[i],v2[i])<<"\n";
}
 
return 0;
}