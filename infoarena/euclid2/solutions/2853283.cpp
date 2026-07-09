#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int x, int y)
{
    int t = 0;
    while(y != 0)
    {
        t = y;
        y = x % y;
        x = t;
    }
    return x;
}

int main()
{
    int *n = new int;
    fin >> *n;
    for(int i = 0; i < *n; i++)
    {
        int t1, t2;
        fin >> t1 >> t2;
        fout << euclid(t1, t2) << '\n';
    }
    delete n;
    fin.close();
    fout.close();
    return 0;
}