#include <iostream>
#include <bits/stdc++.h>
#define NN 1024
using namespace std;
int n,m;
int imax;
int vn[NN],vm[NN];
int a[NN];
int pred[NN];
int mmaxa[NN];
int inversator[NN];
int lll[NN][NN];
vector <int> vv[NN];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
f>>n>>m;

for (int i=1; i<=n; i++){
    f>>vn[i];
}
for (int i=1; i<=m; i++){
    f>>vm[i];
}
int s=0;
for (int i=1; i<=n; i++){
    for (int j=1; j<=m; j++){
        if (vn[i]==vm[j]){
            lll[i][j]=lll[i-1][j-1]+1;
            }


        else{
            lll[i][j]=max(lll[i-1][j], lll[i][j-1]);
        }
    }
    }
    int i=n;
    int j=m;
while ((i>0)&&(j>0)){
    if (lll[i][j]==lll[i-1][j-1]+1){
        a[s]=vn[i];
        s++;

    i--;
    j--;}
    if (lll[i][j]==lll[i-1][j]) {j--;}else {i--;}
}
        g<< lll[n][m]<< endl;
for (int j=s-1; j>=0; j--)
{
    g<<a[j]<<' ';
}
}
















