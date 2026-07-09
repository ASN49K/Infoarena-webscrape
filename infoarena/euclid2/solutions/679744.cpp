#include<fstream>
using namespace std;
int functie( int x, int y)
{
int r;
while(y)
{
r=x%y;
x=y;
y=r;
}
return x;
}
int n,x,y,i;
int main()
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
fin>>n;
for(i=1;i<=n;i++)
{
fin>>x>>y;
fout<<functie(x,y);
fout<<"\n";
}
return 0;
}
