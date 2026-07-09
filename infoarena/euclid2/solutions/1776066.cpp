#include <iostream>
#include <fstream>
using namespace std;

int solve(int x, int y)
{
    int r;
    while(y)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x; cout<<x<<" ";
}

void read()
{
    int n, x, y;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> n;
    while(n)
    {
        fin >> x >> y;
        fout << solve(x,y) << '\n';
        --n;
    }
    fin.close();
    fout.close();
}

int main()
{
    read();
    return 0;
}
