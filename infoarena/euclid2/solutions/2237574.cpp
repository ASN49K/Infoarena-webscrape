#include <bits/stdc++.h>

using namespace std;

int t,a,b,cmmdc(int,int);
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int main()
{

f >> t;
for (;t;t--)
{

f >> a;
f >> b;
g << cmmdc(a,b) << "\n";
}
}
int cmmdc(int x, int y) {

while (x != y ) {
if ( x > y ) x = x - y;

else if ( y > x ) y = y - x;
}
return x;
}
