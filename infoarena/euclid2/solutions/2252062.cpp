#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int Euclid(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int t;
    int x,y;
    fi>>t;
    while(t)
    {
        fi>>x>>y;
        fo<<Euclid(x,y)<<'\n';
        t--;
    }
}
