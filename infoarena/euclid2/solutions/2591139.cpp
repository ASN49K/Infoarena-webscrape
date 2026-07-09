#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid.in");
ofstream fout("euclid.out");

int Solve(int a, int b) {
    int r;
    while (b > 0) {
    r = a % b;
    a = b;
    b = r;
    }
    return a;
}

int main()
{   int x, y;
    int n;
    fin >> n;
    while(n--)
    {
        fin >> x >> y;
        fout << Solve(x, y) << "\n";
    }
    return 0;
}
