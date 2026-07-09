#include<fstream>
using namespace std;
int n, m, i, j, x[1030], y[1030], d[1030][1030], sol[1030], k;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int maxim(int x, int y){
    return (x>y?x:y);
}
int main(){
    in>>n>>m;
    for(i=1; i<=n; i++){
        in>>x[i];
    }
    for(j=1; j<=m; j++){
        in>>y[j];
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(x[i]==y[j])
                d[i][j]=1+d[i-1][j-1];
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
    for(i=1; i<=k; i++)
        out<<sol[k-i+1]<<" ";
return 0;
}
