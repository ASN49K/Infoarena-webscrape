#include <fstream>
#include <algorithm>
#include <vector>

#define nmax 1024

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n;
vector <int> a(nmax), b(nmax), best(nmax);

int main()
{
    f>>m>>n;
    for (int i=0; i<m; i++) f>>a[i];
    for (int i=0; i<n; i++) f>>b[i];

    set_intersection(a.begin(), a.end(), b.begin(), b.end(), best.begin());

    int aux=best.size();
    while (best[aux]==0) --aux;
    g<<aux+1<<'\n';
    for (int i=0; i<aux; i++) g<<best[i]<<' ';

    f.close(); g.close();
    return 0;
}
