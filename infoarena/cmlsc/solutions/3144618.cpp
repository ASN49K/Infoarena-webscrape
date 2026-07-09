#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n, m, M[1025][1025];
int v1[1025], v2[1025], sir[1025];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v1[i];
    for(int j = 1; j <= m; j++)
        cin >> v2[j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
    {
        if(v1[i] == v2[j])
            M[i][j] = M[i-1][j-1] + 1;
        else
            M[i][j] = max(M[i-1][j], M[i][j-1]);
    }
    cout << M[n][m]<<'\n';
    int cnt = M[n][m];
    int x = n;
    int y = m;
    while(cnt)
    {
        if(M[x][y] == M[x-1][y-1] + 1)
        {
            sir[cnt] = v1[x];
            x--;
            y--;
            cnt--;
        }
        else
        {
            if(M[x][y] == M[x-1][y])
                x--;
            else
                y--;
        }

    }
    cnt = M[n][m];
    for(int i = 1; i <= cnt; i++)
        cout << sir[i]<<' ';
    return 0;
}
