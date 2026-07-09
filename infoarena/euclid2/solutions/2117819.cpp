#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int e(int a,int b)
{
int r;
while(b!=0)
{
r=a%b;
a=b;
b=r;
}
return a;
}
int main()
{
int n,a,b,i,r;
fin>>n;
for(i=1;i<=n;i++)
{
fin>>a>>b;
fout<<e(a,b)<<'\n';
}
return 0;
}
