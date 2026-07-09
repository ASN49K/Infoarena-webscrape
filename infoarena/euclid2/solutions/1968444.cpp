#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <queue>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    int r;
    while (b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int n;
    fin >> n;
    for (int i=1; i<=n; i++)
    {
        int a,b;
        fin >> a >> b;
        fout << cmmdc(a,b) << '\n';
    }
}
