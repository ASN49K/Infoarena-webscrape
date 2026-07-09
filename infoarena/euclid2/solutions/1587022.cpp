#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int m,int n)
{while(m!=n)
{if(m>n)
{m=m-n;}
else
{n=n-m;}}
return m;}
int main()
{int T,a,b,i;
f>>T;
for(i=1;i<=T;i++)
{f>>a>>b;
g<<cmmdc(a,b)<<"\n";
cout.flush();}
f.close();
g.close();
return 0;}