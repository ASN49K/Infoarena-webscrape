#include <bits/stdc++.h>

using namespace std;

int t,a,b,cmmdc(int,int);
ifstream f ("euc.in");
ofstream g ("euc.out");

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
