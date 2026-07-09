#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int m, n, v[1050], b[1050], mat[1050][1050], sol[1050];
int main(){
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>v[i];
    for(int i=1;i<=m;i++)
        in>>b[i];

    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
            if(v[i] == b[j]){
                mat[i][j] = mat[i-1][j-1] + 1;
            }
            else{
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }
    out<<mat[n][m]<<endl;
    int k = 0;
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--){
            if(mat[i-1][j-1] + 1 == mat[i][j] && i > 1 && j > 1){
                k++;
                sol[k] = v[i];
                i--;
                j--;
            }
        }
    }
    for(int i=k;i>=1;i--)
        out<<sol[i]<<" ";
}
