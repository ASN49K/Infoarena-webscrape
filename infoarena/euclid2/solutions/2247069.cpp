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
    int t,i,a,b;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<endl;
    }
    return 0;
}
