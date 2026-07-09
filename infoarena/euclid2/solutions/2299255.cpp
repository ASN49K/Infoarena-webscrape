#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

const int NLIM = 100001;

int n, v[NLIM];

int euclid(int a, int b)
{
    int r = a % b;
    while (r)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

void rezolva()
{
    fin >> n;
    for (int i=1; i<=n; i++)
    {
        int x, y;
        fin >> x >> y;
        fout << euclid(x,y) << "\n";
    }

}

int main()
{
    rezolva();
    return 0;
}
