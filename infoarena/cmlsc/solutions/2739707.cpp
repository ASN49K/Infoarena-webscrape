#include <fstream>

using namespace std;

int n, m, i, j;
int v1[1050], v2[1050], d[1050];

int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> v1[i];
    for(i = 1; i <= m; i++)
        cin >> v2[i];
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(v1[i] == v2[j]){
                d[i] = d[i-1] + 1;
                break;
            }
            else
                d[i] = d[i-1];
        }
    }
    cout << d[n] << '\n';
    for(i = 1; i <= n; i++){
        if(d[i] > d[i-1])
            cout << v1[i] << ' ';
    }
    return 0;
}
