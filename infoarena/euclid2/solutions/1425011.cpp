#include<iostream>
#include<fstream>
int main()
{int a,b,t,c,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(i=1;i<=t;i++)
{f>>a; f>>b;
while(a!=b)
if(a>b)
{c=a-b;
a=b;
b=c;}
else
{c=b-a;
b=a;
a=c;}
g<<a<<endl;}
return 0;}