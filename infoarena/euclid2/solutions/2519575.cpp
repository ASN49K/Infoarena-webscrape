#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, a, b;
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        int r = 0;
        fin>>a>>b;
        while(b)
        {
            r  = a % b;
            a = b;
            b = r;
        }
        fout<<a<<'\n';
    }
}
