#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int pd[1025][1025], n, m, a[1025], b[1025], sol[1025], k;

void citire() {
    f >> n >> m;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int j = 1; j <= m; ++j)
        f >> b[j];
}

void rezolva() {
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            if(b[i] == a[j])
                pd[i][j] = pd[i-1][j-1] + 1;
            else
                pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
}

void cmf() {
    for(int i = m, j = n; i;)
        if(b[i] == a[j])
            sol[++k] = a[j], i--, j--;
        else
            if(pd[i-1][j] < pd[i][j-1])
            --j;
        else
            --i;
}

void afisare() {
    g << k << '\n';
    for(int i = k; i > 0; --i)
        g << sol[i] << ' ';
}

int main()
{
    citire();
    rezolva();
    cmf();
    afisare();
    f.close();
    g.close();
    return 0;
}
