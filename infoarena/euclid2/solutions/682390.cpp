#include<iostream>
#include<fstream>
using namespace std;
int euclid(int a, int b)
{
int p;
do
{   p=a%b;
a=b;
b=p;
}while(p!=0);
return a;
}
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long n,x,y,j;
f>>n;
for(j=1;j<=n;j++)   
{
f>>x>>y;
g<<euclid(x,y);
g<<"\n";
}
f.close();
g.close();
return 0;
}
