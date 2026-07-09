#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int mem[1025][1025];

int v[1025];
int w[1025];

stack<int> stiva;

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

    prezent =mem[n][m];

    i=n;j=m;

    while (prezent!=0){

        while (mem[i][j]==prezent)
            j--;
        j++;

        while (mem[i][j]==prezent)
            i--;
        i++;

        stiva.push(v[i]);

        i--;
        prezent--;

    }

    while (!stiva.empty()){
        fout<<stiva.top()<<" ";
        stiva.pop();
    }

    return 0;
}
