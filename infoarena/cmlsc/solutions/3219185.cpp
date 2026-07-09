
#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, i, j, m;
int a[100001], b[100001];
int mat[1024][1024];
int v[100001];
int numara=0;

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;++i){
        fin>>a[i];
    }
    for(j=1;j<=m;++j){
        fin>>b[j];
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            if(a[i]==b[j]){
                mat[i][j]=mat[i-1][j-1]+1;
            }else{
                mat[i][j]=max(mat[i][j-1], mat[i-1][j]);
            }
        }
    }
    fout<<mat[n][m]<<endl;
    i=n;
    j=m;
    while(i>=1 && j>=1){
        if(a[i]==b[j]){
            v[numara++]=a[i];
            i--;
            j--;
        }else if(mat[i-1][j]<mat[i][j-1]){
            j--;
        }else{
            i--;
        }
    }
    for(i=numara-1;i>=0;--i){
        fout<<v[i]<<" ";
    }

    return 0;
}