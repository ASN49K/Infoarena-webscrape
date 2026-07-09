#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025], b[1025], c[1025][1025] ,x[1025];
int m,n,k;

void bt(int i, int j){
    if(i == 0 || j == 0)
        return;
    if(a[i]==b[j]){
        x[k++] = a[i];
        return bt(i-1, j-1);
    }
    if(c[i][j-1] > c[i-1][j])
        return bt(i, j-1);
    return bt(i-1, j);
}

int main(){
    fin >>m>>n;
    for(int i = 1; i <=m; ++i){
        fin >>a[i];
    }
    for(int i = 1; i <=n; ++i){
        fin >>b[i];
    }
    for(int i = 1; i<=m; ++i)
    for(int j = 1; j<=n; ++j){
        if(a[i] == b[j])
            c[i][j] = c[i-1][j-1] + 1;
        else
            c[i][j] = max(c[i-1][j], c[i][j-1]);
    }
    bt(m,n);
    fout<<k<<endl;
    while(--k >= 0){
        fout << x[k]<< " ";
    }
    return 0;
}
