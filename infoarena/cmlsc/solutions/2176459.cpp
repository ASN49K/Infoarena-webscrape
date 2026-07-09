#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair <int, int>
#define pd pair <double, double>
#define pii pair <pi, pi>
#define x first
#define y second
#define sz size()
#define vi vector <int>
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m;
int a[1025],b[1025];
int d[1025][1025];
vi arr;
void Citire(){
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <=m; i++)
        fin>>b[i];
}
void Egal(){
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <=m; j++){
            if (a[i] == b[j]) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i][j-1] , d[i-1][j]);
        }
}
void Sol(){
    int i = n, j = m;
    while (i && j) {
        if (a[i] == b[j]) {
            arr.push_back(a[i]);
            i--,j--;
        }
        else if (d[i][j-1] < d[i-1][j]) i--;
        else j--;
    }
}

int32_t main(){
    Citire();
    Egal();
    Sol();
    fout << arr.sz << "\n";
    for (int i = arr.sz - 1; i >= 0; i--)
        fout<<arr[i]<<' ';
}
