#include<fstream>
#define n_max 1025
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int N, M;

int a[n_max], b[n_max];

int dp[n_max][n_max];


void reconstr(int i, int j){
    if(!i || !j)
       return;

    if(a[i] == b[j]){
        reconstr(i-1, j-1);
        fout << a[i] << " ";
        return;
    }

    if(dp[i-1][j] > dp[i][j-1])
       reconstr(i-1, j);
    else
       reconstr(i, j-1);
}


int main(){
    fin >> M >> N;

    for(int i=1; i<=M; ++i)
        fin >> a[i];
    for(int i=1; i<=N; ++i)
        fin >> b[i];

    for(int i=1; i<=M; ++i)
       for(int j=1; j<=N; ++j)
          if(a[i] == b[j])
             dp[i][j] = dp[i-1][j-1] + 1;
          else
             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    fout << dp[M][N] <<'\n';

    reconstr(M, N);

    fin.close();
    fout.close();

    return 0;
}
