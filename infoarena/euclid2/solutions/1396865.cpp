#include <iostream>

using namespace std;
int cmmdc(int a,int b)
{
    int t;
    while(b>0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
int main()
{
    int i,a,b,n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=0;i<n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
}
