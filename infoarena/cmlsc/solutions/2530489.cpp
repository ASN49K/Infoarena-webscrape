#include <bits/stdc++.h>
#define MAX 1024
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m, v1[MAX], v2[MAX], mat[MAX][MAX], v[MAX] , z;

int main(){
    in>>n>>m;
    for(int i = 1; i <= n; i++)
        in>>v1[i];
    for(int j = 1; j <= m; j++)
        in>>v2[j];

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        if(v1[i] == v2[j])
            mat[i][j] = 1 + mat[i-1][j-1];
        else mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
    }
    for(int i = n, j = m; i;)
        if(v1[i] == v2[j]) v[++z] = v1[i], i--, j--;
        else if(mat[i-1][j] < mat[i][j-1])
            j--;
        else i--;

    for(int i = z; i >= 1; i--)
        out<<v[i]<<" ";

}
