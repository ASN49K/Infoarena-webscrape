#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int x,int y)
{
int d;
while(y!=0)
{
d=x%y;
x=y;
y=d;
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
