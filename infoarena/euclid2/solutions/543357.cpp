#include<iostream>
#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{if(!b) return a;
return cmmdc(b,a%b);}
int main()
{unsigned int a,b,T;
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
f>>T;
for(T;T;--T)
{f>>a>>b;
g<<cmmdc(a,b)<<'\n';}
}