#include<fstream>

using namespace std;

iostream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int x,int y)
{
while(x!=y)
if(x>y)x=x-y;
else y=y-x;
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
