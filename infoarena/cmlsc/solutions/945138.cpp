#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m,n,a[1030],b[1030],tab[1030][1030],d[1030],k=1;

int maxim(int a, int b){
    if(a>b)
        return a;
    else return b;
}

int main()
{
    int mx;
    f>>m>>n;
    for(int i=1;i<=m;i++)
        f>>a[i];
    for(int i=1;i<=n;i++)
        f>>b[i];

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]){
                tab[i][j]=tab[i-1][j-1]+1;
            }
            if(maxim(tab[i][j-1],tab[i-1][j])>tab[i][j])
                tab[i][j]=maxim(tab[i][j-1],tab[i-1][j]);
        }
    }

    g<<tab[m][n]<<"\n";
    mx=tab[m][n];
    for(int i=m;i>=1;i--){
        for(int j=n;j>=1;j--){
            if(a[i]==b[j] && tab[i][j]==mx){
                d[mx]=a[i];
                mx--;
            }
        }
    }

    for(int i=1;i<=tab[m][n];i++)
        g<<d[i]<<' ';


    f.close();
    g.close();
}
