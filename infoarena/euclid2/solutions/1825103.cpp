#include <iostream>
#include <fstream>
#include <cstring>
#define MaxT 100000
using namespace std;
int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    else
        return cmmdc(b,a%b);
}
int main()
{
    ifstream f("euclid.in");
    ofstream g("euclid.out");
    int n , t[MaxT];
    f>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        f>>x>>y;
        g<<cmmdc(x,y)<<endl;
    }

    return 0;
}
