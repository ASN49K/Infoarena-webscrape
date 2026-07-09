#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int x, y, z;
    fin>>x;
    while(fin>>x>>y) {
        while (y) {
            z = y;
            y = x % y;
            x = z;
        }
        fout<<x<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
