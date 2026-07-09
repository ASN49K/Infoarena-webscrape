#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,T;
int cmmdc(int x,int y)
{int r;
while(y)
{r=x%y;
x=y;
y=r;
}
return x;
}
int main()
{f>>T;
for(int i=1;i<=T;i++)
{f>>a>>b;
g<<cmmdc(a,b)<<'\n';
}
return 0;
}
