#include<fstream>
using namespace std;
int n, m, x[1100], y[1100], d[1100][1100], i, j, k, sol[1100];
int maxim(int x, int y){
    return x>y?x:y;
}
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
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=maxim(d[i-1][j], d[i][j-1]);
        }
    }
    i=n;
    j=m;
    while(d[i][j]!=0){
        if(x[i]==y[j]){
            sol[++k]=x[i];
            i--;
            j--;
        }
        else{
            if(d[i-1][j]>d[i][j-1])
                i--;
            else
                j--;
        }
    }
    out<<k<<"\n";
    for(i=k; i>=1; i--)
        out<<sol[i]<<" ";
return 0;
}
