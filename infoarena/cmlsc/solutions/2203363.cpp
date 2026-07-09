#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define cin in
#define cout out

using namespace std;

vector<vector<int> > dynamic_array;
vector<int> lcs;

int calc_lcs(vector<int> a, vector<int> b, int n, int m){
    int i, j;

    for (i = 1; i <= n; ++i){
        for (j = 1; j <= m; ++j){
            if (a[i - 1] == b [j - 1])
                dynamic_array[i][j] = dynamic_array[i - 1][j - 1] + 1;
            else
                dynamic_array[i][j] = max(dynamic_array[i - 1][j], dynamic_array[i][j - 1]);
        }
    }

    i = n;
    j = m;

    while (dynamic_array[i][j]){
        if (dynamic_array[i][j] != max (dynamic_array[i][j - 1], dynamic_array[i - 1][j])){
            lcs.push_back(a[i - 1]);
            i = i - 1;
            j = i - 1;
            continue;
        }
        if (dynamic_array[i][j] == dynamic_array[i - 1][j]){
            i = i - 1;
            continue;
        }
        if (dynamic_array[i][j] == dynamic_array[i][j - 1]){
            j = j - 1;
            continue;
        }
    }

    return dynamic_array[n][m];
}

int main(){
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int n, m;
    int i;

    cin >> n >> m;

    dynamic_array.resize(n + 1);
    for (i = 0; i <= n; ++i)
        dynamic_array[i].resize(m + 1, 0);


    vector<int> a(n + 1);
    vector<int> b(m + 1);

    for (i = 0; i < n; ++i)
        cin >> a[i];

    for (i = 0; i < m; ++i)
        cin >> b[i];

    cout << calc_lcs(a,b,n,m) << '\n';

    for (auto it = lcs.rbegin(); it != lcs.rend(); ++it)
        cout<<*it<<' ';

    in.close();
    out.close();
    return 0;
}
