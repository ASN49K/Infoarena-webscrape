#include<bits/stdc++.h>
#include<fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[2048], b, glo;
int bestTill[2048];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    in>>n>>m;
    for(int i=0;i<n;++i){
        in>>a[i];
    }
    int glo=0, cur=0;
    for(int i=0;i<m;++i){
        in>>b;
        int maxtill=0;
        for(int j=cur;j<n;++j){
            maxtill=max(maxtill, bestTill[j]);
            if(a[j] == b && bestTill[j] <= j){
                bestTill[j]= maxtill+1;
                glo = max(glo, bestTill[j]);
            }
        }
    }
    out<<glo<<'\n';
    for(int i=0, c=0;i<n && c<glo;++i){
        if(bestTill[i] == c+1){
            ++ c;
            out<<a[i]<<' ';
        }
    }
    return 0;
}

