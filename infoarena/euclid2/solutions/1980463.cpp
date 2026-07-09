#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long a,b,i,n,r;
int main()
{
f>>n;
for(i=1;i<=n;i++)
{
f>>a>>b;
do
{
r=a%b;
a=b;
b=r;
}
while(r!=0);
g<<a<<endl;
}
f.close();
g.close();
return 0;
}
