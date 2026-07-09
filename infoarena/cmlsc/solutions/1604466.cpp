#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void cmlsc(const vector<int>& a, const vector<int>& b, vector<int>& rez){
    const int n = a.size(), m = b.size();
    vector<vector<int>> d(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i-1] == b[j-1]){
                d[i][j] = d[i-1][j-1]+1;
            }
            else{
                d[i][j] = max(d[i][j-1], d[i-1][j]);
            }
        }
    }
    for(int i = n, j = m; i > 0 && j > 0; ){
        if(a[i-1] == b[j-1]){
            rez.push_back(a[i-1]);
            --i, --j;
        }
        else if(d[i-1][j] > d[i][j-1]){
            --i;
        }
        else{
            --j;
        }
    }
    reverse(rez.begin(), rez.end());
}

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n, m;
    f >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for(int i = 0; i < n; ++i){
        f >> a[i];
    }
    for(int j = 0; j < m; ++j){
        f >> b[j];
    }
    vector<int> rez;
    cmlsc(a, b, rez);

    g << rez.size() << '\n';
    for(int i = 0; i < rez.size(); ++i){
        g << rez[i] << ' ';
    }
    return 0;
}
