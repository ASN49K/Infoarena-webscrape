#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

const string file = "cmlsc";
const ll INF = 9223372036854775807ll;
const int inf = 2147483647, nmax = 1100;

int n[2], v[2][nmax], pd[nmax][nmax];

int main()
{
    ifstream fin (file+".in");
    ofstream fout (file+".out");
    fin >> n[0] >> n[1];
    for (int t = 0; t < 2; ++t)
        for (int i = 1; i <= n[t]; ++i)
            fin >> v[t][i];
    for (int i = 1; i <= n[0]; ++i)
        for (int j = 1; j <= n[1]; ++j)
            if(v[0][i] == v[1][j])
                pd[i][j] = 1+pd[i-1][j-1];
            else pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
    fout << pd[n[0]][n[1]] << "\n";
    stack<int> sol;
    int I = n[0], J = n[1];
    while(I && J)
        if(v[0][I] == v[1][J]){
            sol.push(v[0][I]);
            --I, --J;
        }else if (pd[I-1][J] > pd[I][J-1])
            --I;
        else --J;
    while(!sol.empty()){
        fout << sol.top() << " ";
        sol.pop();
    }
    return 0;
}
