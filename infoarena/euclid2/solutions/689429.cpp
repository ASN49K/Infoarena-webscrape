#include<iostream.h>
#include<fstream.h>
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,i,t; f>>t;
for (i=1;i<=t;i++)
{
f>>a>>b;
if (a>b) {r=a; a=b; b=r;}
r=a%b;
while (r!=0) {a=b; b=r; r=a%b;}
g<<b<<endl;
}
}