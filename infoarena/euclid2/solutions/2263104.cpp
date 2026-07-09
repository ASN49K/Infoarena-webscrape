#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b,i;

int A(int a, int b)
{
    if(!b)
      return a;
    else
      return A(b,a%b);
}

int main()
{
f>>n;
for(i=1;i<=n;i++)
{
    f>>a>>b;
    g<<A(a,b)<<endl;
}
    return 0;
}
