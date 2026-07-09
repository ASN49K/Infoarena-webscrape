#include <fstream>

using namespace std;

#define N 1024

int v1[N+1], v2[N+1], ma[N+2][N+2], v[N+1];

int main()
{
    ifstream cin ("cmlsc.in");
    ofstream cout ("cmlsc.out");

    int n1, n2, i, l, c, p;

    cin >> n1 >> n2;
    for (i=1; i<=n1; i++)
        cin >> v1[i];
    for (i=1; i<=n2; i++)
        cin >> v2[i];

    for (l=1; l<=n1; l++)
        for (c=1; c<=n2; c++){
            if (v1[l] == v2[c])
                ma[l][c] = ma[l - 1][c - 1] + 1;
            else if (ma[l - 1][c] > ma[l][c - 1])
                ma[l][c] = ma[l - 1][c];
            else
                ma[l][c] = ma[l][c - 1];
        }

    l = n1;
    c = n2;
    p = 0;
    while (l > 0 && c > 0){
        if (v1[l] == v2[c]){
            v[p++] = v1[l];
            l--;
            c--;
        }else if (ma[l][c] == ma[l - 1][c])
            l--;
        else if (ma[l][c] == ma[l][c - 1])
            c--;
    }

    cout << ma[n1][n2] << '\n';
    for (i=p-1; i>=0; i--)
        cout << v[i] << ' ';

    return 0;
}
