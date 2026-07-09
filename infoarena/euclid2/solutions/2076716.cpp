#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int x, y;

int cmmdc (int x, int y)
{
    if (y==0)   return x;
    return cmmdc (y, x%y);
}

int main()
{
    int T;
    fin>>T;
    while (T--)
    {
        fin>>x>>y;
        fout<< cmmdc (x, y) <<'\n';
    }
    fout.close();
    return 0;
}
