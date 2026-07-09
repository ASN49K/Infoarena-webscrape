#include <fstream>
#include <algorithm>
using namespace std;
int v1[1030],v2[1030];
int mat[1030][1030];
int rez[1030];
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int n,m,i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++){
        fin>>v1[i];
    }
    for(i=1;i<=m;i++){
        fin>>v2[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(v1[i]==v2[j]){
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else{
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    fout<<mat[n][m]<<'\n';
    int l=n,c=m,poz=1;
    while(1<=l&&l<=n&&1<=c&&c<=m){
        if(v1[l]==v2[c]){
            rez[poz]=v1[l];
            poz++;l--;c--;
        }
        else{
            if(mat[l-1][c]>mat[l][c-1]){
                l--;
            }
            else{
                c--;
            }
        }
    }
    for(i=poz-1;i>=1;i--){
        fout<<rez[i]<<" ";
    }
    fout<<'\n';
    return 0;
}
