#include<fstream>
using namespace std;
long long n,i,a,b;
int cmmdc( int x,int y)
{
    int r=0;
    while(y)
        {r=x%y;
    x=y;
    y=r;}
    return x;
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
