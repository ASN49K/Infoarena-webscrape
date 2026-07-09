#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;
int a[1050],b[1050];
int v[1050][1050];

void cmlsc()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]){
                v[i][j] = v[i-1][j-1]+1;
            }
            else{
                v[i][j] = max(v[i-1][j],v[i][j-1]);
            }
        }
    }
}

int sir[1050],c;

int backtrack(int i, int j)
{
    if(i != 0 && j != 0){
        if(a[i] == b[j]){
            sir[c] = a[i];
            c++;
            backtrack(i-1,j-1);
        }
        else if(v[i][j-1] > v[i-1][j]) backtrack(i,j-1);
        else{
            backtrack(i-1,j);
        }
    }
}

int main()
{
    fin>>n>>m;
    int i,nr;
    for(i = 1; i <= n; i++){
        fin>>nr;
        a[i] = nr;
    }
    for(i = 1; i <= m; i++){
        fin>>nr;
        b[i] = nr;
    }

    cmlsc();
    fout<<v[n][m]<<"\n";
    backtrack(n,m);
    for(i = c-1; i >= 0; i--){
        fout<<sir[i]<<" ";
    }

}
