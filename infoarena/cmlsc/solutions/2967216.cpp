#include <iostream>
#include <fstream>

using namespace std;

int a[2000][2000];

int main()
{
    int n, m;
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    n+=2; m+=2;
    for(int i=3; i<=n; i++) f>>a[i][1];
    for(int i=3; i<=m; i++) f>>a[1][i];

    for(int i=3; i<=n; i++){
        for(int j=3; j<=m; j++){
            if(a[i][1]==a[1][j]){
                a[i][j]=a[i-1][j-1]+1;
            }
            else{
                a[i][j]=max(a[i-1][j], a[i][j-1]);
            }
        }
    }

    int i=n, j=m, v[a[n][m]+1], p=1;
    while(i>=3 && j>=3){
        if(a[1][j]==a[i][1]){
            v[p++]=a[1][j];
            i--; j--;
        }
        else{
            if(a[i-1][j]>a[i][j-1]) i--;
            else j--;
        }
    }
    g<<a[n][m]<<endl;
    for(int i=1; i<p; i++) g<<v[i]<<" ";
    g.close();
    return 0;
}
