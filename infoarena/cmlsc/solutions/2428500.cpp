#include <fstream>



using namespace std;



short D[1025][1025], n, m, i, j, v1[1024], v2[1024], sol[1024], idx;



int main()

{

    ifstream f("cmlsc.in");

    ofstream g("cmlsc.out");

    f >> n >> m;

    for (i=0;i<n;i++)

        f>>v1[i];

    for (i=0;i<m;i++)

        f>>v2[i];

    for (i=1;i<=n;i++)

        for (j=1;j<=m;j++)

            if (v1[i-1]==v2[j-1])

                D[i][j]+=(D[i-1][j-1]+1);

            else

                if (D[i-1][j] > D[i][j-1])

                    D[i][j] = D[i-1][j];

                else

                    D[i][j] = D[i][j-1];

    for (i=n, j=m; i;)

        if (v1[i-1] == v2[j-1])

            sol[idx++] = v1[i-1], --i, --j;

        else if (D[i-1][j] < D[i][j-1])

            --j;

        else

            --i;

    g << idx << '\n';

    for (i=idx-1;i>=0;--i)

        g << sol[i] << ' ';

    return 0;

}
