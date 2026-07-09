#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int dp[1025][1025], v[1025], w[1025], n, m, sir[1025], k=0;
void citire(){
    int i;
    in >> n >> m;
    for(i=1;i<=n;i++) in >> v[i];
    for(i=1;i<=m;i++) in >> w[i];
}
void cmlsc(int a[], int b[]){
    int i, j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    for(i=n,j=m;i;){
        if(a[i]==b[j]){
            sir[++k] = a[i];
            i--; j--;
        }
        else if(dp[i-1][j]<dp[i][j-1]) j--;
        else i--;
    }
}
void afisare(){
    int i;
    out << k << '\n';
    for(i=k;i>=1;i--)
        out<<sir[i]<<' ';
}
int main()
{
    citire();
    cmlsc(v,w);
    afisare();
    return 0;
}
