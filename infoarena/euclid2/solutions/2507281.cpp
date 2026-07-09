#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

void rezolva(int a, int b)
{
    int r=0;
    while (a)
    {
        r=b%a;
        b=a;
        a=r;
    }
    out<<b<<'\n';
}
int main()
{
    int n,a,b;
    in>>n;

    for (int i=1;i<=n;i++)
    {
        in>>a>>b;
        rezolva(a,b);
    }
}
