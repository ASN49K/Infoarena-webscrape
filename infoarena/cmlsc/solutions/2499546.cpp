#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M, a[1024], b[1024], c[1024][1024], i, j, x, sub[1024];

int main()
{
    fin >> N >> M;
    for (i = 1; i <= N; i ++)
        fin >> a[i];
    for (i = 1; i <= M; i ++)
        fin >> b[i];
    for (i = 1; i <= N ; i ++)
        for (j = 1; j <= M; j ++){
            if (a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    i = N;
    j = M;
    while (c[i][j]){
        while (c[i - 1][j] == c[i][j])
            i --;
        while (c[i][j - 1] == c[i][j])
            j --;
        x ++;
        sub[x] = b[j];
        i --;
        j --;
    }
    fout << c[N][M] << endl;
    for (i = x; i >= 1; i --)
        fout << sub[i] << " ";
    return 0;
}
