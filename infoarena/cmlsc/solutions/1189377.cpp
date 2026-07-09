#include <fstream>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N=1025;
int n,m, a[N], b[N], d[N][N];

void afisare(int l, int co){
    if(l!=0 && co!=0){
        if(a[l]==b[co]){
            afisare(l-1,co-1);
            out<<a[l]<<" ";
        }
        else
            if(d[l-1][co]>d[l][co-1])
                afisare(l-1,co);
            else
                afisare(l,co-1);
    }
}

int main()
{
    int i,j;
    in>>n>>m;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else{
                if(d[i-1][j]>d[i][j-1])
                    d[i][j]=d[i-1][j];
                else
                    d[i][j]=d[i][j-1];
            }
    out<<d[n][m]<<"\n";
    afisare(n,m);
    return 0;
}
