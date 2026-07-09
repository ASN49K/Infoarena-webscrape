#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int sol[1025][1025],sir[1025],a[1025],b[1025];

int max(int a,int b){
    return a>b ? a : b;
}

int main(){
    int n,m;
    fin>>m>>n;
    for (int i=1;i<=m;i++) fin>>a[i];
    for (int i=1;i<=n;i++) fin>>b[i];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (a[i]==b[j]) sol[i][j] = 1 + sol[i-1][j-1];
            else sol[i][j] = max(sol[i-1][j],sol[i][j-1]);
    int l = sol[m][n];
    int i = m;
    int j = n;
    while(i>=1 && j>=1){
        if (a[i] == b[j]){ sir[l] = a[i]; i--; j--; l--;}
        else if (sol[i-1][j] > sol[i][j-1]) i--;
             else j--;
    }
    fout<<sol[m][n]<<"\n";
    for (int i=1;i<=sol[m][n];i++){
        fout<<sir[i]<<" ";
    }
    return 0;
}

