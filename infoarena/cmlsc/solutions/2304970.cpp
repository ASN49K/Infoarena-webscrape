#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int N,M,a[1050],b[1050],i,j,D[1050][1050];
void afisare(int ii, int jj, int pas){
    if(pas){
    if(a[ii]==b[jj]){
        afisare(ii-1,jj-1,pas-1);
        fout<<a[ii]<<" ";
    }
    else
        if(D[ii-1][jj]>D[ii][jj-1])
            afisare(ii-1,jj,pas);
        else
            afisare(ii,jj-1,pas);
    }


}
int main(){
    fin>>N>>M;
    for(i=1;i<=N;i++)
        fin>>a[i];
    for(i=1;i<=M;i++)
        fin>>b[i];
    for(i=1;i<=N;i++)
    for(j=1;j<=M;j++){
        if(a[i]==b[j])
            D[i][j]=D[i-1][j-1]+1;
        else
            D[i][j]=max(D[i-1][j],D[i][j-1]);
    }
    fout<<D[N][M]<<"\n";
    afisare(N,M,D[N][M]);

    return 0;
}
