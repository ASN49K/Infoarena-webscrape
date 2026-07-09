#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int euclid(int a, int b);
int i, n, x, y;
int main()
{
    fin >> n;
    for(i=0; i<n; i++)
    {
        fin >> x >> y;
        fout << euclid(x, y) << '\n';
    }

    return 0;
}

int euclid(int a, int b)
{
    int r = a%b;
    while(r)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}
