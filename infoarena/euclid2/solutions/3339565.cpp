#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd (int a, int b)
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
    int n;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        fin>>x>>y;
        fout<<gcd(x,y)<<"\n";
    }
    return 0;
}
