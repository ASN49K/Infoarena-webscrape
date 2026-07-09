#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025], b[1025];
int d[1025][1025];
int c[1025];
int k = 1025;
int nn,mm;
int cmlsc(){
    for(int n = 1; n<=nn; n++)
    for(int m = 1; m<=mm; m++){
        if(a[n] == b[m])
            d[n][m] = d[n-1][m-1] + 1;
        else
            d[n][m] = max(d[n-1][m], d[n][m-1]);
    }
    return d[nn][mm];
}
void backtr(int i, int j){
    if(i == 0 || j == 0)
        return ;
    if(a[i] == b[j]){
        c[k] = a[i];
        k--;
        backtr(i-1, j-1);
    } else if(d[i][j-1] > d[i-1][j]){
        backtr(i, j-1);
    } else {
        backtr(i-1, j);
    }

}
int main(){
    fin>>nn>>mm;
    for(int i = 1; i<=nn; i++)
        fin>>a[i];
    for(int i = 1; i<=mm; i++)
        fin>>b[i];

    fout << cmlsc()<<"\n";
    backtr(nn,mm);
    k++;
    while(k <= 1025){
        fout <<c[k]<<" ";
        k++;
    }
    return 0;
}
