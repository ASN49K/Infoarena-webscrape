#include<fstream>
using namespace std;
int n, m, x[1300], y[1300], i, j, D[1300][1300], sol[1300], nrsol;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main(){
    in>>n>>m;
    for(i=1; i<=n; i++)
        in>>x[i];
    for(j=1; j<=m; j++)
        in>>y[j];
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(x[i]==y[j])
                D[i][j]=D[i-1][j-1]+1;
            else
                D[i][j]=max(D[i-1][j], D[i][j-1]);
        }
    }
    out<<D[n][m]<<"\n";
    while(D[n][m]!=0){
        if(x[n]==y[m]){
            sol[++nrsol]=x[n];
            n--;
            m--;
        }
        else{
            if(D[n-1][m]>D[n][m-1])
                n--;
            else
                m--;
        }
    }
    for(i=nrsol; i>=1; i--)
        out<<sol[i]<<" ";
return 0;
}
