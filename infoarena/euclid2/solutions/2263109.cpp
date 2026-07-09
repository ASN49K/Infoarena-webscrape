#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int A(int a, int b)
{
    if(!b)
      return a;
    return A(b,a%b);
}

int main()
{int n,a,b;
f>>n;
while(n--)
{
    f>>a>>b;
    g<<A(a,b)<<endl;
}
    return 0;
}
