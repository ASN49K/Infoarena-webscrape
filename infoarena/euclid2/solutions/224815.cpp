#include<iostream>
#include<algorithm>
#include<fstream>

using  namespace std;
int main()
{
long int i,a,b,n,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
if(n>=1 && n<=100000)
{
for(i=n;i>=1;--i)
{
f>>a>>b;
cout<<a<<" "<<b<<endl;
if(a>=2&&a<=2000000000&&b>=2&&b<=2000000000)
{
while(a%b)
{
r=a%b;
a=b;
b=r;
}
g<<b<<endl;
}
}
}
f.close();
g.close();
}