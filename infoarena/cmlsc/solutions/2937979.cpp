#include <iostream>
#include <fstream>
#define is ==
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N = 1030;

int l[N][N], lcs[N], v1[N], v2[N];

int find_lcs(int n, int m){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(v1[i - 1] == v2[j - 1]){
                l[i][j] = l[i - 1][j - 1] + 1;
            }
            else{
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
            }
        }
    }
    int len = l[n][m], cop = len;
    out << len << '\n';
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(v1[i - 1] == v2[j - 1]){
            lcs[len - 1] = v1[i - 1];
            i--; j--; len--;
        }
        else if(l[i - 1][j] > l[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }
    len = cop;
    for(int i = 0; i < cop; i++){
        out << lcs[i] << " ";
    }
    return len;
}

int main(){
    int n, m;
    in >> n >> m;
    for(int i = 0; i < n; i++){
        in >> v1[i];
    }
    for(int i = 0; i < m; i++){
        in >> v2[i];
    }
    find_lcs(n, m);
}