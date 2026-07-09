#include <fstream>
using namespace std;

int euclid(int a, int b, int r)
{
    if (r==0)
        return b;
    else
        euclid(b, r, b%r);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int n, a, b;
    f >> n;
    for (int i=0; i<n; i++)
    {
        f >> a >> b;
        g << euclid(a, b, a%b) << endl;
    }
}
