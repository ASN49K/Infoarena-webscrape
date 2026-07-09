#include <fstream>
#define dmax 1025
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, lcs[dmax][dmax], a[dmax], b[dmax];

void citire();
void pd();

int main(){
    citire();
    pd();
    return 0;
}

void citire(){
    fin>>n>>m;
    int i;
    for(i=1; i<=n; ++i) fin>>a[i];
    for(i=1; i<=m; ++i) fin>>b[i];
}

void pd(){
    int i, j;
    for(i=n; i>=1; --i)
        for(j=m; j>=1; --j)
            if(a[i]==b[j]) lcs[i][j]=lcs[i+1][j+1]+1;
            else lcs[i][j]=max(lcs[i+1][j], lcs[i][j+1]);
    fout<<lcs[1][1]<<'\n'; ++i, ++j;
    while(i<=n && j<=m)
        if(a[i]==b[j]){
            fout<<a[i]<<' ';
            ++i, ++j;
        }
        else    if(lcs[i+1][j]==lcs[i][j]) ++i;
                else ++j;
}
