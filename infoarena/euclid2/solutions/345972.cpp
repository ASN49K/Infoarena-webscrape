#include<iostream>
#include<fstream>
using namespace std;
long cmmdc(long a,long b)
{
    long r=0;

while(b!=0){
r=a%b;
a=b;
b=r;
}
return a;
}
int main ()
{
    long T,a,b;
    ifstream x("euclid2.in");
    ofstream y("euclid2.out");
    x>>T;
    for(long i=1;i<=T;i++)
    {
        x>>a>>b;
        y<<cmmdc(a,b)<<"/n";
    }
    x.close();
    y.close();
    return 0;
}

