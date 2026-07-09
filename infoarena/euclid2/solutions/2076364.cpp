#include <fstream>
#include <iostream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}



int a,b,r,n,i;
int main()
{
    f>>n;

    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }

    return 0;
}
