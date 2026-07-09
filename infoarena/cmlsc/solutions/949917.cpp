#include <fstream>
#include <algorithm>
#include <vector>

#define nmax 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n;
vector <int> best(nmax);
vector <int> a(nmax);
vector <int> b(nmax);

int main()
{
    f>>m>>n;
    for (int i=0; i<m; i++) f>>a[i]; sort(a.begin(), a.end());
    for (int i=0; i<n; i++) f>>b[i]; sort(a.begin(), a.end());

    set_intersection(a.begin(), a.end(), b.begin(), b.end(), best.begin());

    int aux=best.size()-1;
    while (best[aux]==0) --aux;
    g<<aux+1<<'\n';
    for (int i=0; i<=aux; i++) g<<best[i]<<' ';

    f.close(); g.close();
    return 0;
}
