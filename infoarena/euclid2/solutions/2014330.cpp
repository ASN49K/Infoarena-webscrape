#include<iostream>
#include<fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
int i,T;
long long x,y,r;
f >> T;
for(i=1;i<=T;i++)
{
f >> x >> y;
while(y)
{
r = x % y;
x = y;
y = r;
}
g << x << endl;
}
}
