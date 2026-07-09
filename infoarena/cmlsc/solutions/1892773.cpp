#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");


int sol[1025], a[1025], b[1025], D[1025][1025];
int n, i, maxim, pmaxim, M, poz, j, Max,k,m,L;
pair <pair <int, int>, int> l[20001];

//D[i][j] = lungimea subsirului maxim comun dintre cei 2 vectori pana la elementul i al primului vector si j al celui de-al doilea

int main(){
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];

    for(i=1;i<=m;i++)
        fin>>b[i];

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            if(a[i]==b[j]){
                D[i][j] = 1 + D[i-1][j-1];
            } else
                if (D[i-1][j] > D[i][j-1])
                    D[i][j] = D[i-1][j];
                else
                    D[i][j] = D[i][j-1];

    }
    fout<<D[n][m]<<"\n";
    L = D[n][m];
    i = n;
    j = m;
    while (L != 0) {
        if (a[i] == b[j]) {
            sol[L] = a[i];
            L--;
            i--;
            j--;
        } else {
            if (D[i-1][j] > D[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=1;i<=D[n][m];i++){
        fout<<sol[i]<<" ";
    }
    return 0;
}
