#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b)
{
    int c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int euclid_recursiv(int a, int b)
{
    if(b == 0)
        return a;
    return euclid_recursiv(b, a % b);
}

int main()
{
    int n, a, b;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> a >> b;
        fout << euclid(a,b) << '\n';
    }
    return 0;
}
