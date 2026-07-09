#include <fstream>
#include <iostream>

using namespace std;

int e(int a, int b)
{
    if(b==0)
        return a;
    else return e(b, a%b);
}

int main()
{
    fstream f("euclid2.in", ios::in);
    fstream g("euclid2.out", ios::out);
    int n;
    int a,b;
    f>>n;
    for(int i = 0; i<n; ++i)
    {
        f>>a>>b;
        g<<e(a,b)<<'\n';
    }
}
