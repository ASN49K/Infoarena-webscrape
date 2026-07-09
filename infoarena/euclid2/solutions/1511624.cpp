#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void solve();
int cmmdc(int a, int b);

int main ()
{
    
    solve();
    
    return 0;
}

int cmmdc(int a, int b)
{
    if (b == 0)
        return a;
    return cmmdc(b, a%b);
}

void solve()
{
    int n, a, b;
    
    fin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    
}