#include <fstream>

using namespace std;



ifstream f("cmlsc.in");

ofstream g("cmlsc.out");



int a[1025], b[1025], n, m;

int v[1025][1025], sir[1025], k;



void read()

{

    f >> n >> m;

    for(int i = 1; i <= n; ++i)

        f >> a[i];

    for(int j = 1; j <= n; ++j)

        f >> b[j];

}



void solve()

{

    for(int i = 1; i <= n; ++i)

        for(int j  = 1; j <= m; ++j)

            if(a[i] == b[j])

                v[i][j] = v[i - 1][j - 1] + 1;

            else

                v[i][j] = max(v[i][j - 1], v[i-1][j]);;



    int x = n, y = m;

    while(v[x][y])

    {

        while(v[x - 1][y] == v[x][y])

            --x;

        while(v[x][y - 1] == v[x][y])

            --y;

        sir[++k]=a[x];

        --x, --y;

    }



    g << v[n][m] << "\n";

    for(int i = k; i >= 1; --i)

        g << sir[i] << " ";

}



int main()

{

    read();

    solve();

    return 0;

}
