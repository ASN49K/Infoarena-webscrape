#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m;
int a[1025];
struct per{
    int a, i;
};
int b[1025];
int sir[1025];
int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        fin >> b[i];
    }
    int nr = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                sir[nr] = a[i];
                nr++;
                i++;
            }
        }
    }
    fout << nr - 1 << "\n";
    for (int i = 1; i < nr; i++)
    {
        fout << sir[i] << " ";
    }
    return 0;
}