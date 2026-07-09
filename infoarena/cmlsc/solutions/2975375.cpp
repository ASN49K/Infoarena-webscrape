#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short int A[1030],B[1030],sol[1030],a[1030][1030],ucm[1030][1030];
///pair<short int, short int> ucm[1030][1030];

int main()
{
    short int M,N,i,j;
    fin >> M >> N;
    for(i=1;i<=M;i++)
        fin >> A[i];
    for(i=1;i<=N;i++)
        fin >> B[i];
    for(i=1;i<=M;i++){
        for(j=1;j<=N;j++){
            if(A[i] == B[j]){
                a[i][j] = a[i-1][j-1]+1;
                ucm[i][j] = i;
            }
            else{
                if(a[i-1][j]>a[i][j-1]){
                    a[i][j] = a[i-1][j];
                    ucm[i][j] = ucm[i-1][j];
                }
                else{
                    a[i][j] = a[i][j-1];
                    ucm[i][j] = ucm[i][j-1];
                }
            }
        }
    }
    fout << a[M][N] << '\n';
    i = ucm[M][N];
    j = a[M][N];
    while(i>0){
        sol[j] = A[i];
        i = ucm[i-1][N];
        j--;
    }
    for(i=1;i<=a[M][N];i++)
        fout << sol[i] << " ";
    return 0;
}
