#include<fstream>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#include<cstring>
#include<bitset>

#define MAX 1024

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

//ifstream f("in.in");
//ofstream g("out.out");

int d[MAX+5][MAX+5],a[MAX+5],b[MAX+5];
int n,m;
struct{
    int i;
    int j;
}t[MAX+5][MAX+5];


void afis(int x,int y){
    int i = t[x][y].i;
    int j = t[x][y].j;

    //cout<<x<<"-"<<y<<" = "<<i<<" "<<j<<'\n';

    if(d[i][j]!=0){
        afis(i,j);
    }

    if(a[x] == b[y]){
        g<<a[x]<<" ";
    }
}

int main(){

    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>a[i];
    }
    for(int i=1;i<=m;i++){
        f>>b[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == b[j]){
                d[i][j] = d[i-1][j-1] + 1;
                t[i][j].i = i-1;
                t[i][j].j = j-1;
            }else{
                if(d[i-1][j] > d[i][j-1]){
                    d[i][j] = d[i-1][j];
                    t[i][j].i = i-1;
                    t[i][j].j = j;
                }else{
                    d[i][j] = d[i][j-1];
                    t[i][j].i = i;
                    t[i][j].j = j-1;
                }
            }
        }
    }
    t[n+1][m+1].i = n;
    t[n+1][m+1].j = m;


    g<<d[n][m]<<'\n';
    afis(n,m);

    f.close();
    g.close();
    return 0;
}
