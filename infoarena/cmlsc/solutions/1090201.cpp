#include <fstream>
#define nmax 102

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

void citire();
void pd();
void afisare();

int n, m;
int lcs[nmax][nmax];
int a[nmax], b[nmax];

int main(){
    citire();
    pd();
    afisare();
    return 0;
}

void citire(){
    int i, j;
    fin>>n>>m;
    for(i=1; i<=n; ++i) fin>>a[i];
    for(j=1; j<=m; j++) fin>>b[j];
}

void pd(){
    int i, j;
    for(i=n; i>0; i--)
        for(j=m; j>0; j--)
            if(a[i]==b[j])  lcs[i][j]=1+lcs[i+1][j+1];
            else    if(lcs[i][j+1]>lcs[i+1][j]) lcs[i][j]=lcs[i][j+1];
                    else    lcs[i][j]=lcs[i+1][j];
}

void afisare(){
    fout<<lcs[1][1]<<'\n';
    int i=1, j=1;
    while(i<=n && j<=m){
        if(a[i]==b[j]){
            fout<<a[i]<<' ';
            i++, j++;
        }
        else    if(lcs[i][j]==lcs[i+1][j])  i++;
                else    j++;
    }
    fout<<'\n';
}
