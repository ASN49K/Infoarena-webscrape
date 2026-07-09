#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
//#define int long long 

const string FILE_NAME = "cmlsc";
ifstream fin(FILE_NAME + ".in");
ofstream fout(FILE_NAME + ".out");

int n, m, mat[1050][1050] = {0};
vector<int> v, v2;

signed main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; i++){
        int x; fin >> x;
        v.pb(x);
    }

    for(int i = 1; i <= m; i++){
        int x; fin >> x;
        v2.pb(x);
    }
    
    int maxim = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(v[i - 1] == v2[j - 1]){
                mat[i][j] = mat[i-1][j-1] + 1;
                maxim = max(maxim, mat[i][j]);
            }
            else{
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }

    

    int x = n, y = m;
    vector<int> answer;

    while(x >= 1 && y >= 1 && maxim > 0){
        if(x-1 > 1 && mat[x-1][y] == maxim){
            x--;
        }
        else if(y-1 > 1 && mat[x][y - 1] == maxim){
            y--;
        }
        else{
            answer.pb(v[x-1]);
            maxim--;
        }
    }

    fout << answer.size() << "\n";
    for(int i = answer.size() - 1; i >= 0; i--)
        fout << answer[i] << " ";
        
    return 0;
}
