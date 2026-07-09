#include <fstream>
#include <iostream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long n;
long long cmmdc(long long x,long long y){
if(y>x){int aux=x; x=y; y=aux;}
long long c;
while(y){
    c=x%y;
    x=y;
    y=c;
}
return x;
}
int main()
{
   f>>n;
   for(long long i=1;i<=n;i++)
   {
       long long a,b;
       f>>a>>b;
       g<<cmmdc(a,b)<<endl;
   }
    return 0;
}
