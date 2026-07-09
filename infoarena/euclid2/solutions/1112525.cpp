#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
int main()
{int a,b,n;
f>>n;
for(int i=1;i<=n;i++)
	{f>>a>>b;
	g<<gcd(a,b)<<endl;}
f.close();
g.close();
return 0;}