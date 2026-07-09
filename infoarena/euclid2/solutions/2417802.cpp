#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}
int main()
{
    int n, x, y;
    fin>>n;
    while(n--)
    {
        fin>>x>>y;
        fout<<euclid(x, y)<<endl;
    }
    return 0;
}
