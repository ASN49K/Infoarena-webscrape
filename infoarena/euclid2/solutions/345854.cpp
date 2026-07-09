#include<iostream>
#include<fstream>
using namespace std;
long cmmdc(long a,long b)
{
int r;
r=a%b;
while(r!=0)
{
    a=b;
    b=r;
    r=a%b;
}
return b;

}
int main ()
{
ifstream x("euclid2.in");
ofstream y("euclid2.out");
int T,r;
long a,b;
x>>T;
for(int i=1;i<=T;i++)
{
    x>>a>>b;
    y<<cmmdc(a,b);
}
x.close();
y.close();
return 0;
}
