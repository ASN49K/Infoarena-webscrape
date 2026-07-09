#include<bits/stdc++.h>
#include<fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[2048], b[2048], glo, res[2048], c;
int bestTill[2048][2048];
vector<int> r;
int main(){
    int n, m;
    in>>n>>m;
    for(int i=0;i<n;++i){
        in>>a[i];
    }
    for(int i=0;i<m;++i)in>>b[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i]==b[j])
                if(i>0 && j>0)
                    glo = max (glo, bestTill[i][j] = 1+bestTill[i-1][j-1]);
                else
                    glo = max(glo, bestTill[i][j]=1);
            else bestTill[i][j] = max(bestTill[i-1][j], bestTill[i][j-1]);
        }
    }
    out<<glo<<'\n';
    for(int i=n-1, j=m-1; i>=0;){
        if(a[i] == b[j]) res[c++]=a[i], --i, --j;
        else if(bestTill[i][j-1] > bestTill[i-1][j]) --j;
        else -- i;
    }
    for(int i=glo-1;i>-1; --i)out<<res[i]<<' ';
    return 0;
}
