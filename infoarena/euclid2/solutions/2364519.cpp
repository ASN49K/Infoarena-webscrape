#include <fstream>

using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a, b, n, i, rest;
int main()
{
    fin>>n;
    for (i=1; i<=n; i++)
    {
        fin>>a>>b;
        rest=a%b;
        while (rest!=0)
        {
            a=b;
            b=rest;
            rest=a%b;
        }
        fout<<b;
    }
    return 0;
}
