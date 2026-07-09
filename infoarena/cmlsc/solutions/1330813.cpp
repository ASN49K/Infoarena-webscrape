#include <fstream>
#define DIM 1024
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int N,M,a[DIM],b[DIM],D[DIM][DIM],i,j,sir[DIM],k;
int main(){
    fin>>N>>M;
    for(i=1;i<=N;i++)
        fin>>a[i];
    for(i=1;i<=M;i++)
        fin>>b[i];
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            if(a[i]==b[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
    i=N;
    j=M;
    while(i){
        if(a[i]==b[j]){
            sir[++k]=a[i];
            i--;
            j--;
        }
        else{
            if(D[i-1][j]>D[i][j-1])
                i--;
            else
                j--;
        }
    }
    fout<<D[N][M]<<"\n";
    while(k)
        fout<<sir[k--]<<" ";
    fin.close();fout.close();
    return 0;
}
