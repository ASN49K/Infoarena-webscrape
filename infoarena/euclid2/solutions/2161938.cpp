#include <iostream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a, b, r, n;
    fin >> n;
    for (int i=1; i<=n; i++)
    {
        fin >> a >> b;
        while (b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout << a << "\n";
    }
    return 0;
}
