#include<iostream>
#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b) {
  if (a > b)
    return gcd (b, a);
  else if (a == 0)
    return b;
  else return gcd(b%a, a);
}

int main()
{long long a, b, n;
f >> n;
for(int i = 1; i <= n; i++)
    {f >> a >> b;
    g << gcd(a, b) << endl;}
f.close();
g.close();
return 0;}
