#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    long long a,b,r,n;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<endl;
    }
    return 0;
}
