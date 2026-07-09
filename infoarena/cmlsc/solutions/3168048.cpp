#include <bits/stdc++.h>
#define DIM 1050
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n1, n2;
int d[DIM][DIM], v1[DIM], v2[DIM];
int i, j;
vector <int> sol;

int main(){
    fin>>n1>>n2;
    for(i=1; i<=n1; i++)
        fin>>v1[i];
    for(i=1; i<=n2; i++)
        fin>>v2[i];

    for(i=1; i<=n1; i++){
        for(j=1; j<=n2; j++){
            if(v1[i]==v2[j]){
                d[i][j]=d[i-1][j-1]+1;
                sol.push_back(v1[i]);
            }else{
                d[i][j]=max(d[i-1][j], d[i][j-1]);
            }

        }
    }
    fout<<d[n1][n2]<<"\n";
    for(i=0; i<sol.size(); i++)
        fout<<sol[i]<<" ";
}
