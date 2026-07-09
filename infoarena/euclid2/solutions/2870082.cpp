#include <iostream>
#include <fstream>

using namespace std;

const string filename = "euclid2";
ifstream fin(filename + ".in");
ofstream fout(filename + ".out");

int n;

int euclid(int a, int b)
{
    if(a == 0 || b == 0)
        return a + b;
    return euclid(b, a % b);
}

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        fin >> x >> y;
        if(x < y)
            swap(x, y);
        fout << euclid(x, y) << '\n';
    }
    return 0;
}
