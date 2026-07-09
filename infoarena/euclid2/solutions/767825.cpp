#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int x,int y)
{
int d;
while(x!=0)
{
d=y%x;
y=x;
x=d;
}
return x;
}

int main()
{
int n,a,b;
f>>n;
for(int i=1;i<=n;i++)
{
f>>a>>b;
g<<euclid(a,b)<<endl;
}
return 0;
}
