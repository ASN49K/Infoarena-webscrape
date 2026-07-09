#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{if(!b)return a;
return cmmdc(b,a%b);}
int main()
{int a,b;
ifstream f("euclid2.in");
f>>a>>a>>b;
ofstream g("euclid2.out");
g<<cmmdc(a,b)<<"\n";
while(f>>a>>b)g<<cmmdc(a,b)<<"\n";
g.close();}
