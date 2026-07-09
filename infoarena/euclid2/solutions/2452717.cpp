#include <iostream>
#include <fstream>
using namespace std;

int Euclid(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ifstream A("euclid2.in");
    ofstream B("euclid2.out");
    int T,a,b;
    A>>T;
    for(int i=1;i<=T;++i)
    {
        A>>a>>b;
        B<<Euclid(a,b)<<'\n';
    }
    A.close();
    B.close();
    return 0;
}

