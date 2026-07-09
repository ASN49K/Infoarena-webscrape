#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a,int b)
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
    ifstream reader("euclid2.in");
    ofstream writer("euclid2.out");
    int t;
    reader>>t;
    int x,y;
    for(int i=0;i<t;++i)
    {
        reader>>x>>y;
        writer<<euclid(x,y)<<'\n';
    }
    return 0;
}

