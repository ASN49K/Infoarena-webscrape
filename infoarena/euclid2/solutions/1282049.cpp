#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.in");
    int t;
    f>>t;
    int x,y;
    while(t)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<"\n";
        t--;
    }
    return 0;
}
