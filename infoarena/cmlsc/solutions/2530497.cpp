#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#define NMAX 1030
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int v1[NMAX],v2[NMAX],M[NMAX][NMAX];
vector<int>sol;

int main() {
    int n, m,i,j;
    fin >> n >> m;


    for(i = 1; i <= n; ++i)
        fin >> v1[i];
    for(i = 1; i <= m; ++i)
        fin >> v2[i];

    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j)
        {
            if(v1[i] == v2[j])
                M[i][j] = 1 + M[i-1][j-1];
            else
                M[i][j] = max(M[i-1][j], M[i][j-1]);
        }
    i=n;
    j=m;
    while(i){
        if(v1[i] == v2[j])
        {
            sol.push_back(v1[i]);
            i--;
            j--;
        }
        else
        {
            if(M[i][j-1]<M[i-1][j])
                i--;
            else
                j--;
        }
    }
    fout<<sol.size()<<"\n";
    reverse(sol.begin(),sol.end());
    for(int i =0; i <sol.size(); ++i)
        fout << sol[i] <<" ";
    fout<<"\n";
}
