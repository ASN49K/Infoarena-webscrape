#include <iostream>
#include <fstream>

using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int euclid(int a,int b)
{
    while(a!=b && a>0 && b>0)
    {
        if(a>b)
            a %= b;
        else
            b %= a;
    }
    if(a>b)
    return a;
    else return b;
}
int main()
{
    int T;
    f>>T;
    for(int i=1;i<=T;i++)
    {
        int a,b;
        f>>a>>b;
        g<<euclid(a,b)<<"\n";
    }
    return 0;
}
