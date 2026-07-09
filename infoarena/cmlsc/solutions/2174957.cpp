#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int nmax = 1026;

int a[nmax],b[nmax];

void lcs(int a[], int b[], int n, int m);

int main(){
int n,m;

f>>n>>m;
for(int i=0;i<n;++i)
    f>>a[i];
for(int j=0;j<m;++j)
    f>>b[j];

lcs(a,b,n,m);

return 0;
}

void lcs(int a[], int b[], int n, int m){
int L[n+1][m+1];

for(int i=0;i<=n;++i)
for(int j=0;j<=m;++j){
    if(i==0 || j==0)
        L[i][j] = 0;
    else if(a[i-1] == b[j-1])L[i][j] = L[i-1][j-1] + 1;
    else L[i][j] = max(L[i-1][j], L[i][j-1]);
}

int index = L[n][m];
int go = index;

int lcs[index+1];
int i = n, j = m;
while(i > 0 && j > 0){
    if(a[i-1] == b[j-1])
    {
        lcs[index-1] = a[i-1];
        index--;i--;j--;
    }
    else if(L[i-1][j] > L[i][j-1])
        i--;
    else j--;
}

g<<go<<'\n';
for(int i=0;i<go;++i)
    g<<lcs[i]<<" ";
g<<'\n';
}
