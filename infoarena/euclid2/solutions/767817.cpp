#include<fstream>
using namespace std;

iostream f("euclid2.in");
ofstreeam g("euclid2.out");

void euclid(int x, int y)
{
while(x!=y)
if(x>y)x-=y;
else y-=x;
return x;
}

int main()
{
int n,x,y;
f>>n;
for(int i=1;i<=n;i++)
{
f>>x>>y;
g<<euclid(x,y)<<endl;
}
g.close();
f.close();
return 0;
}
