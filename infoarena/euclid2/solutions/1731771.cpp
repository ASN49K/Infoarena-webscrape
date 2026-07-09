#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int n;
int euclid(int a, int b);

int main()
{
    int a, b;
    fin>>n;
    for (int i=1; i<=n; i++)
    {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
    return 0;
}
int euclid(int a, int b)
{
    if(!b)
        return a;
    return euclid (b, a % b);
}
