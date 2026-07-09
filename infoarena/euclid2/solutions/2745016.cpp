#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n, a, b;
    fin >> n;
    for(int i = 0; i < n; ++i)
    {
        fin >> a >> b;
        while(a && b)
        {
            if(a > b) a = a % b;
            else b = b % a;
        }
        fout << a + b; // a + 0 sau b + 0;
    }
    return 0;
}
