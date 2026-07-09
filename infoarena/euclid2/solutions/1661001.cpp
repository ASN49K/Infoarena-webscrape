#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long T,a,b,i;
int euclid (int a, int b)
{
    int c;
    while (b) {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{ f>>T;
  for (i=1;i<=T;i++) {
    f>>a>>b;
    g<<euclid(a,b)<<"\n";
  }

    return 0;
}
