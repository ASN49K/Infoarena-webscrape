#include<iostream>
#include<fstream>
using namespace std;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b,i;
f>>T;
for(i=1;i<=T;i++)
{f>>a>>b;
while(a!=b)
{if(a>b)
{a=a-b;}
else
{b=b-a;}}
g<<a<<"\n";}
f.close();
g.close();
return 0;}