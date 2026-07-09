#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int L[260][260], x[260], a[260], b[260];
char U[260][260];
int main()
{   int M,N,i,j,k;
    fin>>M>>N;
    for(i=1;i<=M;i++)
        fin>>a[i];
    for(i=1;i<=N;i++)
        fin>>b[i];
    for(i=1;i<=M;i++){
        for(j=1;j<=N;j++){
            if(a[i]==b[j]){
                L[i][j]=L[i-1][j-1]+1;
                U[i][j]=1;
            }
            else{
                if(L[i][j-1]>L[i-1][j]){
                    L[i][j]=L[i][j-1];
                    U[i][j]=-1;
                }
                else{
                    L[i][j]=L[i-1][j];
                    U[i][j]=0;
                }
            }
        }
    }
    fout<<L[M][N]<<"\n";
    k=0;i=M;j=N;
    while(i>=1&&j>=1){
        if(a[i]==b[j]){
            k++;
            x[k]=a[i];
            i--;j--;
        }
        else{
            if(U[i][j]==0){
                i--;
            }
            else j--;
        }
    }
    for(i=k;i>=1;i--)
        fout<<x[i]<<" ";
    fin.close();
    fout.close();
    return 0;
}
