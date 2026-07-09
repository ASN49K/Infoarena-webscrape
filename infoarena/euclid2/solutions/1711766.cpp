#include <iostream>
#include <fstream>

using namespace std;

int t;

long long cmmdc(long long a, long long b)
{
    int r;
    /*while(a!=b)
    {
        if(a>b) a=a-b;
            else b=b-a;
    }
    return a;*/
    r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    long long a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        g << cmmdc(a,b) <<"\n";
    }
    return 0;
}
