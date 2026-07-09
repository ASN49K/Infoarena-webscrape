#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int mem[1025][1025];

int v[1025];
int w[1025];

queue<int> coada;

int main() {

    int i,j,n,m,prezent=1;

    fin>>n>>m;

    for(i=1;i<=n;i++)
        fin>>v[i];

    for(j=1;j<=m;j++)
        fin>>w[j];

    for(i=1;i<=n;i++){

        for(j=1;j<=m;j++)
            if(mem[i][j-1] == mem[i-1][j] && v[i]==w[j]){
                mem[i][j] = mem[i][j-1]+1;
                if(mem[i][j] == prezent){
                    coada.push(v[i]);
                    prezent++;
                }

            }
            else
                mem[i][j] = max(mem[i][j-1],mem[i-1][j]);

    }
/*
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            cout<<mem[i][j]<<" ";

        cout<<"\n";
    }

*/

    fout<< mem[n][m]<<"\n";

    while (!coada.empty()){
        fout<<coada.front()<<" ";
        coada.pop();
    }

    /*
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(mem[i][j]==prezent){
                fout<<v[i]<<" ";
                prezent++;
            }
*/

    return 0;
}
