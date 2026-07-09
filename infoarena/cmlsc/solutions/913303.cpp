#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
short n, m;
int a[1025], b[1025];
short d[1025][1025];
vector<int> sol;

int umple_mat() {
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++) {
            if(a[j] == b[i])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j]=max(d[i][j-1], d[i-1][j]);
        }
    }
    /*
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++) {
                cout<<d[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    return d[m][n];
}

void afis_rasp(){
    int i , j;
    i=m;
    j=n;
    while(i && j){
        if(a[j]==b[i]){
            sol.push_back(a[j]);
            i--;
            j--;
        }
        else if (d[i][j] == d[i][j-1])
            --j;
        else
            --i;
    }
}

int main() {
    fi>>n>>m;
    memset(d[0],0,n);
    for(int i=1; i<=n; i++) {
        fi>>a[i];
    }
    for(int i=1; i<=m; i++) {
        fi>>b[i];
    }
    fo<<umple_mat()<<'\n';
    afis_rasp();
    for(int i=sol.size()-1;i>=0;i--)
        fo<<sol[i]<<' ';
}
