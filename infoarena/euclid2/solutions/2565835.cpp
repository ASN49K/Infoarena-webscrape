#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n, a, b, r;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> a >> b;
        if(a > b)
            swap(a,b);
        while(a != 0)
        {
            r = b % a;
            b = a;
            a = r;
        }
        fout  << b;
    }
    return 0;
}
