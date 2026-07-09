#include<fstream>
using namespace std;
long int euclid(long int a,long int b)
{
long int rest;
while(a!=0)
{
rest=b%a;
b=a;
a=rest;
}
return b;
}
int main(){
	long int a,b,n,i;
ofstream g("euclid2.out");
ifstream f("euclid2.in");
f>>n;
for(i=1;i<=n;i++)
{
f>>a>>b;

g<<euclid(a,b)<<"\n";
}
g.close();

}