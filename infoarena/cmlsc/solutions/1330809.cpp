#include <fstream>
#define DIM 1030
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short N,M,a[DIM],b[DIM],D[DIM][DIM],sir[DIM],k;
int main(){
    fin>>N>>M;
    for(int i=1;i<=N;i++)
        fin>>a[i];
    for(int j=1;j<=M;j++)
        fin>>b[j];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(a[i]==b[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
    fout<<D[N][M]<<"\n";
    for(int i=N,j=M;i;){
        if(a[i]==b[j]){
            sir[++k]=a[i];
            i--;
            j--;
        }
        else
            if(D[i-1][j]>D[j][i-1])
                i--;
            else
                j--;
    }
    while(k)
        fout<<sir[k--]<<" ";
    fin.close();fout.close();
    return 0;
}

