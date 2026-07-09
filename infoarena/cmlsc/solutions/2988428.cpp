#include <bits/stdc++.h>
using namespace std;

const string file_name = "cmlsc";
ifstream fin(file_name + ".in");
ofstream fout(file_name + ".out");

int n, m, v[1030], v2[1030], mat[1040][1040];

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> v[i];

    for(int i = 1; i <= m; i++){
        fin >> v2[i];
    }

    int p = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(v[i] == v2[j])
                mat[i][j] = p++;
            else
                mat[i][j] = mat[i][j] + mat[i][j-1] + mat[i-1][j] - mat[i-1][j-1];
        }
    }

    int k = 1;

    fout << mat[n][m] << "\n";

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << mat[i][j] << " ";
            if(mat[i][j] == k && v[i] == v2[j]){
                fout << v[i] << " ";
                k++;
            }

        }
        cout << "\n";
    }

    return 0;
}
