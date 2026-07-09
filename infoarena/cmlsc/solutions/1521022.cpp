#include<fstream>
#include<vector>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int DP[1030][1030], a[1030], b[1030], Sol[1030];
int n, m, k;


void citire()
{
    int i;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
}

void dinam()
{
    int i, j;

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++){
            if(a[i] == b[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }

    g<<DP[n][m]<<"\n";

    i=n; j=m;
    while(i!=0 || j!=0){
        if(DP[i][j] == DP[i-1][j-1] + 1){
            Sol[++k] = a[i];
            i--; j--;
        }
        else{
            if(DP[i][j] == DP[i-1][j])
                i--;
            else
                j--;
        }
    }

    for(i=k; i>0; i--)
        g<<Sol[i]<<" ";
    g<<"\n";

}

int main()
{
    citire();
    dinam();
    return 0;
}
