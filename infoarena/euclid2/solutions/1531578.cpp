#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a,int b)
{
    int c=a%b;
    while(c!=0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}
int main()
{
    int n;
    in>>n;
    int a,b;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
