#include<iostream>
#include<fstream>
using namespace std;
struct numar {int a,b;};
int cmmdc (int a,int b)
{int r;
	while(r)
{r=a%b;
a=b;
b=r;};
return a;}

numar v[100];
int main ()
{int i,n;
ifstream f("euclid1.in");
ofstream g("euclid2.out");
f>>n;
for(i=1;i<=n;i++) f>>v[i].a>>v[i].b;
for(i=1;i<=n;i++) g<<cmmdc(v[i].a,v[i].b)<<endl;
f.close();
g.close();
return 0;
}