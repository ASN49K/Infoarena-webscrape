#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short int A[1030],B[1030],sol[1030],a[1030][1030];
pair<short int, short int> ucm[1030][1030];

int main()
{
    short int M,N,i,j,k,i1,j1;
    fin >> M >> N;
    for(i=1;i<=M;i++)
        fin >> A[i];
    for(i=1;i<=N;i++)
        fin >> B[i];
    for(i=1;i<=M;i++){
        for(j=1;j<=N;j++){
            if(A[i] == B[j]){
                a[i][j] = a[i-1][j-1]+1;
                ucm[i][j].first = i;
                ucm[i][j].second = j;
            }
            else{
                if(a[i-1][j]>a[i][j-1]){
                    a[i][j] = a[i-1][j];
                    ucm[i][j].first = ucm[i-1][j].first;
                    ucm[i][j].second = ucm[i-1][j].second;
                }
                else{
                    a[i][j] = a[i][j-1];
                    ucm[i][j].first = ucm[i][j-1].first;
                    ucm[i][j].second = ucm[i][j-1].second;
                }
            }
        }
    }
    fout << a[M][N] << '\n';
    i = ucm[M][N].first;
    j = ucm[M][N].second;
    k = a[M][N];
    for(k=a[M][N];k>0;k--){
        sol[k] = A[i];
        i1 = ucm[i-1][j-1].first;
        j1 = ucm[i-1][j-1].second;
        i = i1;
        j = j1;
    }
    for(i=1;i<=a[M][N];i++)
        fout << sol[i] << " ";
    return 0;
}
