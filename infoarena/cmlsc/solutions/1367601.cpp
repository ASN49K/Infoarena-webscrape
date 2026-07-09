#include <fstream>
#define DIM 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int N,M,a[DIM],b[DIM],D[DIM][DIM],sir[DIM],k;
int main(){
    fin>>N>>M;
    for(int i=1;i<=N;i++)
        fin>>a[i];
    for(int i=1;i<=M;i++)
        fin>>b[i];
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(a[i]==b[j])
                D[i][j]=1+D[i-1][j-1];
            else
                D[i][j]=max(D[i-1][j],D[i][j-1]);
    fout<<D[N][M]<<"\n";
    while(D[N][M]){
        if(a[N]==b[M]){
            sir[++k]=a[N];
            N--;
            M--;
        }
        else
            if(D[N][M-1]>D[N-1][M])
                M--;
            else
                N--;
    }
    for(int i=k;i>=1;i--)
        fout<<sir[i]<<" ";
    fin.close();fout.close();
    return 0;
}
