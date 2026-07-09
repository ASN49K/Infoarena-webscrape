#include<fstream>
#include<vector>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

vector <int> Sol;
int DP[1030][1030], a[1030], b[1030];
int n, m;


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
    for(i=1; i<=m; i++){
        if(a[1] == b[i])
            DP[1][i] = 1;
        else
            DP[1][i] = DP[1][i-1];
    }
    for(i=1; i<=n; i++){
        if(b[1] == a[i])
            DP[i][1] = 1;
        else
            DP[i][1] = DP[i-1][1];
    }

    for(i=2; i<=n; i++)
        for(j=2; j<=m; j++){
            if(a[i] == b[j])
                DP[i][j] = DP[i-1][j-1] + 1;
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }

    g<<DP[n][m]<<"\n";

    i=n; j=m;
    while(i!=0 || j!=0){
        if(DP[i][j] == DP[i-1][j-1] + 1){
            Sol.push_back(a[i]);
            i--; j--;
        }
        else{
            if(DP[i][j] == DP[i-1][j])
                i--;
            else
                j--;
        }
    }

    for(i=Sol.size() - 1; i>=0; i--)
        g<<Sol[i]<<" ";
    g<<"\n";

}

int main()
{
    citire();
    dinam();
    return 0;
}
