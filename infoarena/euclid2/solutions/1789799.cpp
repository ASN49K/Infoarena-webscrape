#include<fstream>
using namespace std;
long long n,i,a,b;
long long  cmmdc( long long x,long long  y)
{
    long long r=0;
   if(b==0)
    return a;
   else
    return  cmmdc(b,a%b);
}
int main()
{ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>n;
for(i=1;i<=n;i++)
{in>>a>>b;
out<<cmmdc( a,b)<<endl;}
    return 0;
}
