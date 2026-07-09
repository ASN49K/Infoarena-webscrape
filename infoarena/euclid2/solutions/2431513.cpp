#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x,y,n,i;
void cmmdc(int a,int b)
{
    int r;
     while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<endl;
}

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        cmmdc(x,y);
    }
    return 0;
}
