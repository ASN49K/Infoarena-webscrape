#include <iostream>
#include <fstream>

using namespace std;

int c[1025][1025];
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void backtrack(int a[], int b[], int i, int j)
{
    if(i!=0 && j!=0){
    if(a[i]==b[j]){
        backtrack(a,b,i-1,j-1);
        out<<a[i]<<" ";
    } else{
        if(c[i][j-1]>c[i-1][j]) backtrack(a,b,i,j-1);
        else backtrack(a,b,i-1,j);
    }
    }
}

void lcs(int a[], int n, int b[], int m)
{
    /*int c[n+1][m+1];
    for(int i=0; i<=n; i++) c[i][0]=0;
    for(int i=0; i<=m; i++) c[0][i]=0;*/
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else if(c[i][j-1]>c[i-1][j]) c[i][j]=c[i][j-1];
                 else c[i][j]=c[i-1][j];
    out<<c[n][m]<<endl;
    backtrack(a, b, n, m);
}

int main()
{

    int n, m;
    in>>n>>m;
    int a[n+1], b[m+1];
    for(int i=1; i<=n; i++) in>>a[i];
    for(int i=1; i<=m; i++) in>>b[i];
    lcs(a,n,b,m);
    return 0;
}
