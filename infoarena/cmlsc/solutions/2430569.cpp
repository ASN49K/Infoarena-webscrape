#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, i, j, a[1024], b[1024], r[1024], k = 0, sir[1024];

int main()
{
    in >> n >> m;
    for(i = 1; i <= n; i++)
        in >> a[i];

    for(j = 1; j <= m; j++)
        in >> b[j];

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(a[i] == b[j] && r[b[j]] == 0) {
                k++;
                sir[k] = b[j];
            }
        }
    }

    cout << "\n" << k << "\n";
    for(i = 1; i <= k; i++) {
        cout << sir[i] << " ";
    }

    return 0;
}
