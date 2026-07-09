#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

stack <int> s;
int n, m, crt;
int v[1050], w[1050], d[1050][1050];

int main (){
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>v[i];
    for(int i=1; i<=m; i++)
        fin>>w[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v[i] == w[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);

    fout<<d[n][m]<<"\n";
    crt=d[n][m];
    while(crt)
        if(v[n] == w[m]){
            s.push(v[n]);
            n--; m--; crt--;
        }else
            if(d[n-1][m] > d[n][m-1])
                n--;
            else
                m--;

    while(!s.empty()){
        fout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
