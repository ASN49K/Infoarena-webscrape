#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t,a,b;
    f>>t;
    while(t!=0)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
        t--;
    }
    return 0;
}
