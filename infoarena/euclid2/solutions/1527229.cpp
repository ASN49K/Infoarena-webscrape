#include<iostream>
#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{long long a, b, n, t;
f >> n;
for(int i = 1; i <= n; i++)
    {f >> a >> b;
    while(b != 0)
        {
        t = b;
        b = a % b;
        a = t;
        }
    g<<a<<endl;}
f.close();
g.close();
return 0;}
