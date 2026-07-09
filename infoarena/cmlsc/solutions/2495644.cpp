#include <fstream>
using namespace std;

int x[1030],y[1030],rez[1030][1030],poz[1030],k=0;

void solutii(int i,int j)
{
    if(i<1 && j<1){
        ;
    }else{
        if(y[i]==x[j]){
            solutii(i-1,j-1);
            poz[++k]=i;
        }else{
            if(rez[i-1][j]>rez[i][j-1]){
                solutii(i-1,j);
            }else{
                solutii(i,j-1);
            }
        }
    }
}

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n,m;
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>x[i];
        rez[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        f>>y[i];
        rez[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(y[i]==x[j]){
                rez[i][j]=rez[i-1][j-1]+1;
            }else{
                rez[i][j]=max(rez[i][j-1],rez[i-1][j]);
            }
        }
    }
    g<<rez[m][n]<<'\n';
    solutii(m,n);
    for(int i=1;i<=k;i++){
        g<<y[poz[i]]<<" ";
    }
    return 0;
}
