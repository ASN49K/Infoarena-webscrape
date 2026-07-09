#include<fstream>
using namespace std;
int n, m, i, j, a[1030], b[1030], d[1030][1030], sol[1030], k;
int maxim(int x, int y){
    return x<y?y:x;
}
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main(){
    in>>n>>m;
    for(i=1; i<=n; i++)
        in>>a[i];
    for(j=1; j<=m; j++)
        in>>b[j];
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(a[i]!=b[j])
                d[i][j]=maxim(d[i-1][j], d[i][j-1]);
            else
                d[i][j]=1+d[i-1][j-1];
        }
    }
    i=n;
    j=m;
    while(i!=0 && j!=0){
        if(a[i]==b[j]){
            sol[++k]=a[i];
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
    for(i=k; i>=1; i--)
        out<<sol[i]<<" ";
return 0;
}
