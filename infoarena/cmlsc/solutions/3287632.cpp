#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int maxs = 1024;

int a[maxs], b[maxs];

vector <int> v;

int main()
{
    int n, m, mini, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    mini = min(n, m);
    for (int i = 1; i <= mini; i++){
        if (a[i] == b[i]){
            cnt++;
            v.push_back(a[i]);
        }
    }
    fout << cnt << '\n';
    for (int i = 1; i <= cnt; i++){
        fout << v[i] << ' ';
    }
    return 0;
}
