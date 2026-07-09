#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a,int b)
{
    if(!b) return a;
    if(a>b) return cmmdc(a-b,b);
    return cmmdc(a,b-a);
}

int main()
{
    int n,a,b;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
