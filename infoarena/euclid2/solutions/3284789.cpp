#include <iostream>
#include <fstream>

using namespace std;
ifstream fcin("euclid2.in");
ofstream fout("euclid2.out");

int a, b, n;

int main()
{
    fcin>>n;
    for (int i=1; i<=n; i++)
    {
        fcin>>a>>b;
        int r;
        while (b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<"\n";
    }
}
