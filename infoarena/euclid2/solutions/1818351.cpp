#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int n, x, y, r;
    fin >> n;

    for(int i=1;i<=n;i++)
    {
        fin >> x >> y;
        while(y)
        {
            r=x%y;
            x=y;
            y=r;
        }
        fout << x << "\n";
    }
    return 0;
}
