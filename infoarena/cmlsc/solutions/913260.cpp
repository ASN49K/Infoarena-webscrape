#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
short n, m;
char a[1024], b[1024];
short d[1025][1025];
vector<char> sol;

int umple_mat() {
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++) {
            if(a[j-1] == b[i-1])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j]=max(d[i][j-1], d[i-1][j]);
        }
    }
    return d[m][n];
}

void afis_rasp(){
    int i , j;
    i=m;
    j=n;
    while(i && j){
        if(d[i-1][j-1]+1 == d[i][j]){
            sol.push_back(a[j-1]);
            i--;
            j--;
            continue;
        }
        if(d[i-1][j] == d[i][j]){
            j--;
            continue;
        }
        if(d[i][j-1] == d[i][j]){
            i--;
            continue;
        }
    }
}

int main() {
    fi>>n>>m;
    memset(d[0],0,n);
    for(int i=0; i<n; i++) {
        fi>>a[i];
    }
    for(int i=0; i<m; i++) {
        fi>>b[i];
    }
    fo<<umple_mat()<<'\n';
    afis_rasp();
    for(int i=sol.size()-1;i>=0;i--)
        fo<<sol[i]<<' ';
}
