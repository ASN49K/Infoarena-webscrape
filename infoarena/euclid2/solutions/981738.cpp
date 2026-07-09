#include<fstream>
int cmmdc(int a,int b)
{if(!b)return a;
return cmmdc(b,a%b);}
int main()
{int a,b;
std::ifstream f("euclid2.in");
f>>a>>a>>b;
std::ofstream g("euclid2.out");
g<<cmmdc(a,b)<<"\n";
while(f>>a>>b)g<<cmmdc(a,b)<<"\n";
g.close();}
